//
// Created by shachafk@wincs.cs.bgu.ac.il on 19/11/2019.
//
//
#include "../include/Watchable.h"


Movie::Movie(long id, const std::string& name, int length, const std::vector<std::string>& tags):name(name),Watchable(id,length,tags){}
//std::string Movie::toString(bool print_full=false) const {return nullptr;} //return the string name
//Movie::Watchable* Movie::getNextWatchable(Session&) const {return nullptr;}//return &this+1} //To implement




