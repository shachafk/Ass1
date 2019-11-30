//
// Created by shachafk@wincs.cs.bgu.ac.il on 21/11/2019.
//
#include "../include/User.h"
#include "../include/Action.h"
#include "../include/Session.h"

void DuplicateUser::act(Session & sess) {
    std::vector<std::string> *input = sess.getInputVector();
    if (input->size() < 3) {
        std::string errorMsg = "DuplicateUser Error: Invalid Input";
        error(errorMsg);//call error func who changes action status to ERROR
    } else {
        if (sess.getUsersMap()->count(input->at(1)) == 0) {//if original user dosent exist
            std::string errorMsg = "DuplicateUser Error: This user doesn't exist";
            error(errorMsg);//call error func who changes action status to ERROR
        } else if (sess.getUsersMap()->count(input->at(2)) > 0) {//if new username already exist
            std::string errorMsg = "DuplicateUser Error: new user name already exist";
            error(errorMsg);//call error func who changes action status to ERROR
        } else {
            std::unordered_map<std::string, User *>::const_iterator iter = sess.getUsersMap()->find(input->at(1));
            User *u = iter->second;
            std::string name = input->at(2);
            User* newUser = u->clone();
            sess.getUsersMap()->insert(std::make_pair(name, newUser));//inserts new user to map
            newUser->setName(name);
            complete();
        }
    }
}

 std::string DuplicateUser::toString() const {
     std::string status = getEnumStringFromInt(this->getStatus());
     return "DuplicateUser " + status;
 }

BaseAction* DuplicateUser::clone() const{ return new DuplicateUser(*this);}
