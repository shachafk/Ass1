//
// Created by shachafk@wincs.cs.bgu.ac.il on 21/11/2019.
//

#include "../include/Action.h"
#include "../include/User.h"
#include "../include/Session.h"



BaseAction* ChangeActiveUser::clone() const { return new ChangeActiveUser(*this);}


void ChangeActiveUser::act(Session &sess) {
    std::vector<std::string> *input = sess.getInputVector();
    if (input->size() < 2) {//validates input vector contains a name
        std::string errorMsg = "ChangeActiveUser Error: Invalid Input";
        error(errorMsg);//call error func who changes action status to ERROR
    } else {
        std::string name = input->at(1);
        std::unordered_map<std::string, User *> *map = sess.getUsersMap();
        if (map->count(name) > 0) { //name exists in usermap
            sess.setActiveUser(map->at(name));
            complete();
        } else {
            std::string errorMsg = "ChangeActiveUser Error: the user " + name + " does not exist";
            error(errorMsg);
        }
    }
}


std::string ChangeActiveUser::toString() const{
    std::string status = getEnumStringFromInt(this->getStatus());
    return "ChangeActiveUser " + status;
}

