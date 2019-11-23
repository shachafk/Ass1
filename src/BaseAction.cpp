//
// Created by shachafk@wincs.cs.bgu.ac.il on 21/11/2019.
//

#include "../include/Action.h"

//Rule of 3/5 TBD


BaseAction::BaseAction():status(ActionStatus::PENDING),errorMsg() {
    castEnumArray[0] = "PENDING";
    castEnumArray[1] = "COMPLETED";
    castEnumArray[2] = "Error";
}
ActionStatus BaseAction::getStatus() const { return  status; }
void BaseAction::complete(){status=ActionStatus::COMPLETED;}
void BaseAction::error(const std::string& errorMsg) {
    status=ActionStatus::ERROR;
    this->errorMsg = errorMsg;
    std::string toPrint = "Error " + errorMsg;
    std::cout<< toPrint << std::endl;
};
std::string BaseAction::getErrorMsg() const { return errorMsg;};

std::string BaseAction::getEnumStringFromInt(int i){ //this metgot return the string that fit i number.
    return castEnumArray[i];
}



