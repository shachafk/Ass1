//
// Created by shachafk@wincs.cs.bgu.ac.il on 19/11/2019.
//


#include "../include/Watchable.h"


Watchable::Watchable(long id, int length, const std::vector<std::string>& tags):id(id),length(length),tags(tags){} //id should be the location in the content vector
Watchable::Watchable(Watchable& Watchable) {copy(Watchable);}
Watchable::~Watchable(){ // destructor

}
std::string Watchable::toString() const {return "";}
Watchable* Watchable::getNextWatchable(Session&) const {return nullptr;}
void Watchable::copy (Watchable& Watchable){
    id = Watchable.getId();
    length = Watchable.getLength();
    tags = Watchable.getTag();
}
void clean(){};

//getters

 long Watchable::getId() const {return this->id;}
int Watchable::getLength() const { return this->length;}
const std::vector<std::string> & Watchable::getTag(){return this->tags;}
