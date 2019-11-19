//
// Created by shachafk@wincs.cs.bgu.ac.il on 19/11/2019.
//


#include "../include/Watchable.h"


Watchable::Watchable(long id, int length, const std::vector<std::string>& tags):id(id),length(length),tags(tags){}
Watchable::~Watchable(){}
std::string Watchable::toString() const {return "";}
Watchable* Watchable::getNextWatchable(Session&) const {return nullptr;}