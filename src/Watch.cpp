//
// Created by shachafk@wincs.cs.bgu.ac.il on 21/11/2019.
//
#include "../include/Action.h"
#include "../include/Session.h"
#include "../include/User.h"
#include <iostream>
#include <sstream>
#include<map>


void Watch::act(Session& sess) {
    std::vector <std::string> *input=sess.getInputVector();
    int id;
    try {
         id = std::stoi(input->at(1));
    }
    catch (const std::exception& e){
        error("Watch Error: content ID is not valid"); //if number is too big to cast
        return;
    }

    if ( id > 0 and (unsigned) id < sess.getContent().size()){ //check if the content exists
        play(sess.getContent().at(id),sess);
    }
    else {
        error("Watch Error: content ID is not valid");
    }
}

std::string Watch::toString() const {
    std::string status = getEnumStringFromInt(this->getStatus());
    return "Watch " + status;
}

void Watch::play(Watchable* watchable,Session& sess){
    std::cout<< "Watching " + watchable->toString() << std::endl;
    complete();
    sess.getActiveUser()->addToHistory(watchable); // add the watchable to user history
    sess.getActiveUser()->getAvailable()->erase(watchable->getId());
    std::vector<std::string> tags=watchable->getTag();//for each watched content get its tags
    for(int i=0;i<tags.size();i++){
        (*sess.getActiveUser()->getSorted())[tags[i]]++;
    }

    Watchable* WatchNext = watchable->getNextWatchable(sess);
    if (WatchNext != nullptr) {
        std::cout << "We recommend watching  " + WatchNext->toString() + ",continue watching? [Y/N]" << std::endl;
        std::string answer;
        getline(std::cin,answer);
        std::istringstream iss(answer);
        std::string word;
        iss >> word;
        if (word == "Y" or word == "y"){
            // need to create new action watch and to watch recommended
            sess.getInputVector()->at(1) = std::to_string(WatchNext->getId());
            sess.watchAgain(new Watch());
        }
        else if (word == "N" or word == "n") {
            return;
        }
        else {
            std::cout <<"Invalid input"<< std::endl;
        }
    }

}


BaseAction* Watch::clone() const{ return new Watch(*this);}
