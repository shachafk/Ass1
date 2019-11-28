#include "../include/Action.h"
#include "../include/Session.h"
#include "../include/User.h"
#include <iostream>



void CreateUser::act(Session& sess){ //should decide weather user is valid and change status accordingly
    std::vector <std::string> *input=sess.getInputVector();
    if (input->size() < 3){ //validates input vector contains name&type
        std::string errorMsg = "CreateUser Error: Invalid Input";
        error(errorMsg);//call error func who changes action status to ERROR
    }
    else {
        std::string name = input->at(1);
        std::string type = input->at(input->size() - 1);

        if (sess.getUsersMap()->count(name) > 0) {//checks if username already exist in userMap returns error if it does
            std::string errorMsg = "CreateUser Error: the user " + name + " already exists";
            error(errorMsg);//call error func who changes action status to ERROR
        }
        else {
            switch (getEnumMap()[type]) {
                default: {
                    std::string errorMsg = "CreateUser Error: Recommendation type is invalid";
                    error(errorMsg);
                    break;
                }
                case len: {
                    LengthRecommenderUser *u = new LengthRecommenderUser(name);
                    sess.getUsersMap()->insert(std::make_pair(name, u));
                    u->loadAvailable(sess);
                    complete();
                    break;
                }
                case rer: {
                    RerunRecommenderUser *r = new RerunRecommenderUser(name);
                    sess.getUsersMap()->insert(std::make_pair(name, r));
                    r->loadAvailable(sess);
                    complete();
                    break;
                }
                case gen: {
                    GenreRecommenderUser *g = new GenreRecommenderUser(name);
                    sess.getUsersMap()->insert(std::make_pair(name, g));
                    g->loadAvailable(sess);
                    complete();
                    break;
                }


            }


        }
    }

    }

std::string CreateUser::toString() const{
    std::string status = getEnumStringFromInt(this->getStatus());
    return "createUser " + status;
}


BaseAction* CreateUser::clone() const{ return new CreateUser(*this);}
