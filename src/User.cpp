//
// Created by shachafk@wincs.cs.bgu.ac.il on 19/11/2019.
#include "../include/User.h"

//Rule of 3/5 TBD


User::User(const std::string &name):name(name),history() {}

Watchable* User::getRecommendation(Session& s) {};
std::string User::getName() const{
    return name;
}
std::vector<Watchable*> User::get_history() const{return history;}


void User::addToHistory(Watchable* toAdd){
    history.push_back(toAdd);
}

