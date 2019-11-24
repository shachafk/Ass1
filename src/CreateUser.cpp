#include "../include/Action.h"
#include "../include/Session.h"
#include "../include/User.h"
#include <iostream>


//
// Created by shachafk@wincs.cs.bgu.ac.il on 21/11/2019.
//TBD error+complete

void CreateUser::act(Session& sess){ //should decide weather user is valid and change status accordinly
    std::vector <std::string> *input=sess.getInputVector();
    std::string name;
    std::string type;
    if (input->size()>3) { // if user has more then one username
        for(int i=1;i<input->size()-1;i++){
            name=name+input->at(i);
        }
        type=input->at(input->size()-1); //TBD make sure size-1 or size
    }
    else { //User has only one user name
        name = input->at(1);
        type = input->at(2);
    }

    if (sess.getUsersMap().count(name) > 0){//checks if username already exist in userMap returns error if it does
        //create user func changes action status to ERROR
        std::string errorMsg = "CreateUser Error: the user " + name + " already exists";
        error(errorMsg);

    }
    else{
        const std::string &name = name;
        switch (input->at(input->size()-1)) { //TBD what to insert
            case "len":
                LengthRecommenderUser *u = new LengthRecommenderUser(
                        name); //TBD where to delete that heap memory
                sess.getUsersMap().insert(std::make_pair(name, u));
                complete();
                break;
            case "rer":

                RerunRecommenderUser *r = new RerunRecommenderUser(
                        name);//TBD where to delete that heap memory
                sess.getUsersMap().insert(std::make_pair(name, r));
                complete();
                break;
            case "gen":
                GenreRecommenderUser *g = new GenreRecommenderUser(
                        name);//TBD where to delete that heap memory
                sess.getUsersMap().insert(std::make_pair(name, g));
                complete();
                break;
            default:
                std::string errorMsg = "CreateUser Error: Recommendation type is invalid";
                error(errorMsg);
                break;

    }


            }

    }

//virtual std::string toString() const;
