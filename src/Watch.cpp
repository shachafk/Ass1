//
// Created by shachafk@wincs.cs.bgu.ac.il on 21/11/2019.
//
#include "../include/Action.h"
#include "../include/Session.h"
#include "../include/User.h"
#include <iostream>


void Watch::act(Session& sess) {
    std::vector <std::string> *input=sess.getInputVector();
    int id;
    try {
         id = std::stoi(input->at(1));
    }
    catch (const std::exception& e){} //if number is too big to cast

    if ( id < sess.getContent().size()){ //check if the content exists
        play(sess.getContent()[id],sess);
        complete();
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
    sess.getActiveUser()->addToHistory(watchable); // add the watchable to user history
    Watchable* recommended = sess.getActiveUser()->getRecommendation(sess);
    if (recommended != nullptr) {
        std::cout << "We recommend watching  " + recommended->toString() + ",continue watching? [Y/N]" << std::endl;
        std::string answer;
        std::cin >> answer;
        if (answer == "Y"){
            // need to create new action watch and to watch recommended
        }
        else if (answer == "N") {
            return;
        }
    }

}


