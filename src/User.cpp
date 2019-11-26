//
// Created by shachafk@wincs.cs.bgu.ac.il on 19/11/2019.
#include "../include/User.h"
#include "../include/Session.h"

//Rule of 3/5 TBD


User::User(const std::string &name):name(name),history() {}

User::User(const User& other){//copy constructor
    name = other.name;
    for (int i=0; i< other.history.size();i++){ //copy history
        history.push_back(other.history.at(i)->clone());
    }
    for (auto it = other.available.begin(); it != other.available.end(); it ++){ //copy available
        available.insert((std::make_pair((*it).first,(*it).second->clone())));
    }
}

void User::loadAvailable(Session& s){ //load all content from content vector to map
    // Available map will hold all content that were never watched by the user
    for (int i=1; i < s.getContent().size(); i++){
        available.insert(std::make_pair(s.getContent().at(i)->getId(),s.getContent().at(i)));
    }
}

Watchable* User::getRecommendation(Session& s) {};
std::string User::getName() const{
    return name;
}
std::vector<Watchable*> User::get_history() const{return history;}


void User::addToHistory(Watchable* toAdd){
    history.push_back(toAdd);
}

std::map<long, Watchable*>* User::getAvailable(){
    return &available;
}


void User::copyAvailable(std::map<long, Watchable*>* toCopy) {
    std::map<long, Watchable *>::iterator it;
    for (it = toCopy->begin(); it != toCopy->end(); it++) {
        available.insert((*it));
    }
}
