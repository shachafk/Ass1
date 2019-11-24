//
// Created by shachafk@wincs.cs.bgu.ac.il on 21/11/2019.
//
#include "../include/Action.h"
#include "../include/Session.h"
#include "../include/User.h"
#include <iostream>


void Watch::act(Session& sess) {
    std::vector <std::string> *input=sess.getInputVector();
    int id = std::stoi(input->at(1));

}

std::string Watch::toString() const {
    std::string status = getEnumStringFromInt(this->getStatus());
    return "Watch " + status;
}

