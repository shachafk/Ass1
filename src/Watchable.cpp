//
// Created by shachafk@wincs.cs.bgu.ac.il on 19/11/2019.
//


#include "../include/Watchable.h"


Watchable::Watchable(long id, int length, const std::vector<std::string>& tags):id(id),length(length),tags(tags){}
Watchable::Watchable(const Watchable &Watchable) : id(Watchable.getId()), length(Watchable.getLength()), tags(Watchable.getTag()) {}
Watchable::~Watchable(){}
std::string Watchable::toString() const {return "";}
Watchable* Watchable::getNextWatchable(Session&) const {return nullptr;}
void copy (const Watchable &Watchable){
    id(Watchable.getId())
}
void clean();

//getters

long Watchable::getId() {return this->id;}
int Watchable::getLength(){ return this->length;}
std::vector<std::string>& Watchable::getTag(){return this->tags;}