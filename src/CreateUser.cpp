#include "../include/Action.h"
#include "../include/Session.h"
#include "../include/User.h"
#include <iostream>


//
// Created by shachafk@wincs.cs.bgu.ac.il on 21/11/2019.
//TBD error+complete

void CreateUser::act(Session& sess){ //should decide weather user is valid and change status accordinly
    std::vector <std::string> *input=sess.getInputVector();
    std::string name = input->at(1);
    std::string type=input->at(input->size()-1); //TBD make sure size-1 or size

    if (sess.getUsersMap()->count(name) > 0){//checks if username already exist in userMap returns error if it does
        std::string errorMsg = "CreateUser Error: the user " + name + " already exists";
        error(errorMsg);//call error func who changes action status to ERROR
    }
    else{
        //const std::string &name_ = name;
        switch (getEnumMap()[type]) { //TBD what to insert
            default: {
                std::string errorMsg = "CreateUser Error: Recommendation type is invalid";
                error(errorMsg);
                break;
            }
            case len: {
                LengthRecommenderUser *u = new LengthRecommenderUser(name); //TBD where to delete that heap memory
                sess.getUsersMap()->insert(std::make_pair(name, u));
                complete();
                break;
            }
            case rer: {
                RerunRecommenderUser *r = new RerunRecommenderUser(name);//TBD where to delete that heap memory
                sess.getUsersMap()->insert(std::make_pair(name, r));
                complete();
                break;
            }
            case gen:{
                GenreRecommenderUser * g = new GenreRecommenderUser(name);//TBD where to delete that heap memory
                sess.getUsersMap()->insert(std::make_pair(name, g));
                complete();
                break;
                }


    }


    }

    }

     std::string CreateUser::toString() const{
         std::string status = getEnumStringFromInt(this->getStatus());
         return "createUser " + status;
    }
