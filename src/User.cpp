//
// Created by shachafk@wincs.cs.bgu.ac.il on 19/11/2019.
#include "../include/User.h"
#include "../include/Session.h"
#include <map>
#include <vector>

//Rule of 3/5 TBD


User::User(const std::string &name):history(),name(name),available(),sortedTags() {}

User::~User() = default;
User &User::operator=(const User& u) { //copy assignment
    if (this==&u){
        return *this;
    }
    else {
        this->copy(u);
        return *this;
    }
}



User::User(const User& other):history(),name(other.name),available(),sortedTags() {//copy constructor
    name = other.name;
    for (int i=0; (unsigned)i< other.history.size();i++){ //copy history
        history.push_back(other.history.at(i));
    }
    for (auto it = other.available.begin(); it != other.available.end(); it ++){ //copy available
        available.insert((std::make_pair((*it).first,(*it).second)));
    }
    for (auto it = other.sortedTags.begin(); it!= other.sortedTags.end(); it++){
        sortedTags.insert((*it));
    }
}

void User::loadAvailable(Session& s) { //load all content from content vector to map
    // Available map will hold all content that were never watched by the user
    for (int i = 1;  (unsigned) i < s.getContent().size(); i++) {
        available.insert(std::make_pair(s.getContent().at(i)->getId(),s.getContent().at(i)));
        std::vector<std::string> tags = available[s.getContent().at(i)->getId()]->getTag();//get tags vector from curr content
        std::vector<std::string>::iterator it;
        for (it = tags.begin(); it != tags.end(); it++) { //add all tags to map
            sortedTags.insert(std::make_pair((*it), 0));
        }

    }
}

std::string User::getName() const{
    return name;
}
std::vector<Watchable*> User::get_history() const{return history;}
std::vector<Watchable*>* User::getHistory() { return &history;}


void User::addToHistory(Watchable* toAdd){
    history.push_back(toAdd);
}

std::map<long, Watchable*>* User::getAvailable()  {
    return &available;
}
std::map<std::string, int>* User::getSorted() {
    return &sortedTags;
}

void User::copy(const User &user) {
    history.clear();
    for (int i=0; (unsigned) i < user.history.size(); i++){
        history.at(i) = user.history.at(i);
    }
    available.clear();
    for (auto it = user.available.begin(); it != user.available.end(); it++){
        available.insert(std::make_pair((*it).first,(*it).second));
    }
    sortedTags.clear();
    for (auto it = user.sortedTags.begin(); it!= user.sortedTags.end(); it++){
        sortedTags.insert((*it));
    }
}


void User::setName(std::string s){
    name=s;
}

