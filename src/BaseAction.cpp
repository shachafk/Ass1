//
// Created by shachafk@wincs.cs.bgu.ac.il on 21/11/2019.
//

#include "../include/Action.h"

//Rule of 3/5 TBD


BaseAction::BaseAction():status(ActionStatus::PENDING),errorMsg() {}
ActionStatus BaseAction::getStatus() const { return  status; }
void BaseAction::complete(){status=ActionStatus::COMPLETED;}
void BaseAction::error(const std::string& errorMsg) {
    status=ActionStatus::ERROR;
    // need to add the errorMsg TBD
};
std::string BaseAction::getErrorMsg() const { return errorMsg;};


