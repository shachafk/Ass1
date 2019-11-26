//
// Created by shachafk@wincs.cs.bgu.ac.il on 19/11/2019.
//
//
#include "../include/Watchable.h"
#include "../include/Session.h"
#include "../include/User.h"

//Rule of 3/5 TBD


Movie::Movie(long id, const std::string &name, int length, const std::vector<std::string>& tags): Watchable(id, length, tags),name(name){
    setType(1);
}

Movie::Movie(const Movie &Movie): Watchable((Watchable &) Movie), name(Movie.name) {}

Watchable* Movie::clone(){ return new Movie(*this);}


std::string Movie::toString() const {
    std::vector<std::string> tag = getTag();
    std::string tagString = "[";
    for (int i=0;(unsigned)i<tag.size();i++){
        if (i>0){
            tagString = tagString + ",";
        }
        tagString = tagString + tag.at(i);
    }
    tagString = tagString + "]";
    std::string toReturn;
    toReturn = std::to_string(getId()) + ". " +  getName() + " " + std::to_string(getLength())+ " minutes " + tagString;
    return toReturn;
}
Movie::Watchable* Movie::getNextWatchable(Session& s)  const {
    return s.getActiveUser()->getRecommendation(s); //return by recommendation
}


//getters
std::string Movie::getName() const {return this->name;}