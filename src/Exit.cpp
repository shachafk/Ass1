//
// Created by shachafk@wincs.cs.bgu.ac.il on 21/11/2019.
//

#include "../include/Action.h"
#include "../include/User.h"
#include "../include/Session.h"
#include "../include/Watchable.h"


void Exit::act(Session &sess) {
    complete();
}

std::string Exit::toString() const{
    std::string status = getEnumStringFromInt(this->getStatus());
    return "Exit " + status;
}