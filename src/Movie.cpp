//
// Created by shachafk@wincs.cs.bgu.ac.il on 19/11/2019.
//
//
#include "../include/Watchable.h"


Movie::Movie(long id, const std::string *name, int length, const std::vector<std::string>& tags): name(*name), Watchable(id, length, tags){}

Movie::Movie(const Movie &Movie): Watchable(Movie),name(Movie::getName()) {}
std::string Movie::toString(bool print_full) const {return "";} //return the string name
Movie::Watchable* Movie::getNextWatchable(Session&) const {return nullptr;}//return &this+1} //To implement
std::string Movie::toString() const {return"";}


//getters
std::string Movie::getName(){return this->name;}