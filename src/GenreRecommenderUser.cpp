//
// Created by amitmich@wincs.cs.bgu.ac.il on 21/11/2019.
//
#include "../include/User.h"

//Rule of 3/5 TBD

GenreRecommenderUser::GenreRecommenderUser(const std::string& name):User(name){};
User* GenreRecommenderUser::clone(std::string name_) {
    GenreRecommenderUser *other=new GenreRecommenderUser(name_);
    other->copyHistory(get_history());
    other->copyAvailable(getAvailable());
    return other;
}
 Watchable* GenreRecommenderUser::getRecommendation(Session& s){return nullptr;}

