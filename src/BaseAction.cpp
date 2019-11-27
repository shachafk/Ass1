//
// Created by shachafk@wincs.cs.bgu.ac.il on 21/11/2019.
//

#include "../include/Action.h"

//Rule of 3/5 TBD


BaseAction::~BaseAction()= default; //destructor


BaseAction::BaseAction():errorMsg(),status(ActionStatus::PENDING) {
    castEnumArray[0] = "PENDING";
    castEnumArray[1] = "COMPLETED";
    castEnumArray[2] = "Error";
    u_mapStringValues.insert(std::make_pair("Default", RecommendationType::Default));
    u_mapStringValues.insert(std::make_pair("len", RecommendationType::len));
    u_mapStringValues.insert(std::make_pair("gen", RecommendationType::gen));
    u_mapStringValues.insert(std::make_pair("rer", RecommendationType::rer));

}

BaseAction::BaseAction(const BaseAction& other){ //copy constructor
    errorMsg = other.errorMsg;
    status = other.status;
    castEnumArray[0] = "PENDING";
    castEnumArray[1] = "COMPLETED";
    castEnumArray[2] = "Error";
    u_mapStringValues.insert(std::make_pair("Default", RecommendationType::Default));
    u_mapStringValues.insert(std::make_pair("len", RecommendationType::len));
    u_mapStringValues.insert(std::make_pair("gen", RecommendationType::gen));
    u_mapStringValues.insert(std::make_pair("rer", RecommendationType::rer));
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
std::map<std::string, RecommendationType> BaseAction::getEnumMap() {return u_mapStringValues;}

std::string BaseAction::getEnumStringFromInt(int i) const { //this method return the string that fit i number.
    return castEnumArray[i];
}

std::string BaseAction::getError() const{
    return getErrorMsg();
}

