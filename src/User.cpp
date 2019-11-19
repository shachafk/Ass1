//
// Created by shachafk@wincs.cs.bgu.ac.il on 19/11/2019.
#include "../include/User.h"

User::User(const std::string &name):name(name),history() {}

Watchable* User::getRecommendation(Session& s) {};
std::string User::getName() const{
    return name;
}
std::vector<Watchable*> User::get_history() const{return history}



