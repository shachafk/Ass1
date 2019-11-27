//
// Created by shachafk@wincs.cs.bgu.ac.il on 19/11/2019.
#include "../include/User.h"
#include "../include/Session.h"
#include <map>
#include <vector>

//Rule of 3/5 TBD


User::User(const std::string &name):history(),name(name),sortedTags() {}

User::~User()  = default;


User::User(const User& other){//copy constructor
    name = other.name;
    for (int i=0; (unsigned)i< other.history.size();i++){ //copy history
        history.push_back(other.history.at(i)->clone());
    }
    for (auto it = other.available.begin(); it != other.available.end(); it ++){ //copy available
        available.insert((std::make_pair((*it).first,(*it).second->clone())));
    }
}

void User::loadAvailable(Session& s) { //load all content from content vector to map
    // Available map will hold all content that were never watched by the user
    for (int i = 1;  (unsigned) i < s.getContent().size(); i++) {
        available.insert(std::make_pair(s.getContent().at(i)->getId(), s.getContent().at(i)));
        std::vector<std::string> tags = s.getContent().at(i)->getTag();//get tags vector from curr content
        std::vector<std::string>::iterator it;
        for (it = tags.begin(); it != tags.end(); it++) { //add all tags to map
            sortedTags.insert(std::make_pair((*it), 0));
        }
        for (int i = 1; (unsigned) i < s.getContent().size(); i++) {
            available.insert(std::make_pair(s.getContent().at(i)->getId(), s.getContent().at(i)));
        }
    }
}

std::string User::getName() const{
    return name;
}
std::vector<Watchable*> User::get_history() const{return history;}


void User::addToHistory(Watchable* toAdd){
    history.push_back(toAdd);
}

std::map<long, Watchable*>* User::getAvailable()  {
    return &available;
}
std::map<std::string, int>* User::getSorted() {
    return &sortedTags;
}

void User::copyHistory(std::vector<Watchable *> hist) {
    for (int i = 0; (unsigned) i < hist.size(); i++) {
        history.push_back(hist.at(i));
    }
}

void User::copyTags(std::map<std::string, int> toCopy){
    std::map<std::string,int>::iterator it;
    for(it=toCopy.begin();it!=toCopy.end();it++){
        sortedTags.insert((*it));
    }
}

void User::copyAvailable(std::map<long, Watchable*>* toCopy) {
    std::map<long, Watchable *>::iterator it;
    for (it = toCopy->begin(); it != toCopy->end(); it++) {
        available.insert((*it));
    }
}
