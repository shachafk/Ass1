//
// Created by shachafk@wincs.cs.bgu.ac.il on 19/11/2019.
//
using namespace std;
#include <iostream>
#include <fstream>
#include <sstream>
#include "../include/Session.h"
#include "../include/json.hpp"
#include "../include/Watchable.h"
#include "../include/User.h"
#include "../include/Action.h"
//Rule of 3/5 TBD
//Session constructor
Session::Session(const std::string &configFilePath):content(),actionsLog(),userMap(),activeUser(){
    const std::string &name = "default";
    LengthRecommenderUser *l = new LengthRecommenderUser(name);
    userMap.insert(std::make_pair(name,l));
    this->loadContents(configFilePath); //load all available contents from the json file to content vector
    s_mapStringValues.insert(std::make_pair("createuser", StringValue::CreateUser));
    s_mapStringValues.insert(std::make_pair("changeactiveuser", StringValue::changeActiveUser));
    s_mapStringValues.insert(std::make_pair("deleteuser", StringValue::deleteUser));
    s_mapStringValues.insert(std::make_pair("duplicateuser", StringValue::DuplicateUser));
    s_mapStringValues.insert(std::make_pair("exit", StringValue::Exit));
    s_mapStringValues.insert(std::make_pair("printactionslog", StringValue::PrintActionsLog));
    s_mapStringValues.insert(std::make_pair("printcontentlist", StringValue::PrintContentList));
    s_mapStringValues.insert(std::make_pair("printwatchhistory", StringValue::PrintWatchHistory));
    s_mapStringValues.insert(std::make_pair("watch", StringValue::Watch));
}
Session::~Session(){
    for (int i=0; i< content.size(); i++) { //delete all movie and episode from content vector
        if (content[i] != nullptr)
            delete (content[i]);
    }
    for (int i=0; i< actionsLog.size();i++){ //delete all logs from actionlog
        if (actionsLog[i] != nullptr)
            delete (actionsLog[i]);
    }
    for (auto it = userMap.begin();it!=userMap.end();it++ ){ //delete all users from usermap
        delete(it->second);
    }
};
void Session::start() { //this method should initialize default user with alg len recommendation then wait for the user to enter an action to execute
    cout << "SPLFLIX is now on!" << endl;
        mainLoop();
}

void Session::mainLoop(){
    inputVector.clear(); //clear the vector so new input will be inserted
    std::string input;
    getline(cin,input);
    istringstream iss(input);
    string word;
    while(iss >> word) {
        inputVector.push_back(word);
    }
    route();
}

/*
    switch(std::stoi(action)) { //checks which action requested by the user and manages suitable steps
        case "createuser":
            {
                std::string name = "";
                std::string type = "";
                name = input.substr(11);//cuts action from input string
                name = name.substr(0, name.length() - 3);//cuts type from input string
                type = input.substr(input.length() - 4);//TBD make sure it is the right use of substring
                if (userMap.count(name) > 0)//checks if username already exist in userMap
                    //create user func changes action status to ERROR
                    const std::string &name = name;
                switch (std::stoi(type)) {
                    case "len":
                            LengthRecommenderUser *u = new LengthRecommenderUser(
                                    name); //TBD where to delete that heap memory
                            userMap.insert(std::make_pair(name, u)); //TBD add createuser func
                        break;
                    case "rer":

                            RerunRecommenderUser *r = new RerunRecommenderUser(
                                    name);//TBD where to delete that heap memory
                            userMap.insert(std::make_pair(name, r));//TBD add to createuser func
                        break;
                    case "gen":
                            GenreRecommenderUser *g = new GenreRecommenderUser(
                                    name);//TBD where to delete that heap memory
                            userMap.insert(std::make_pair(name, g));//TBD add to createuser func
                        
                        break;
                    deafult: //create user changes action status to ERROR
                }

            }
            break;
    }
    */





//getters
std::vector<Watchable*> *Session::getContent(){
    return &content;
}
std::unordered_map<std::string,User*> Session::getUsersMap(){
    return userMap;
}
std::vector<BaseAction*> Session::getActionsLog(){
    return actionsLog;
}
User* Session::getActiveUser(){
    return activeUser;
}
    std::vector<std::string>* Session::getInputVector(){
    return &inputVector;
}


void Session::loadContents (const std::string &configFilePath) {
    std::ifstream i(configFilePath);
    nlohmann::json j;
    i >> j;
    long id_ = 0;
    // go over all movies and insert each movie to content vector
            for (int i = 0; i < j["movies"].size(); i++,id_++) {
                long id = id_;
                const string name = j["movies"][i]["name"];
                int len = j["movies"][i]["length"];
                const std::vector<std::string> tags = j["movies"][i]["tags"];
                Movie *m1 = new Movie(id, &name, len, tags);
                content.push_back(m1);
            }
    // go over all tv series and insert all episodes to content vector
            for (int i = 0; i < j["tv_series"].size(); i++) {
               int len = j["tv_series"][i]["episode_length"];
               const std::vector<std::string> tags = j["tv_series"][i]["tags"];
               const string seriesName  = j["tv_series"][i]["name"];
               const std::vector<int> numOfEpisodes = j["tv_series"][i]["seasons"];

              for ( int i1=0;i1< numOfEpisodes.size();i1++){ //for each seasons create all episodes
                  for (int i2=1; i2<= numOfEpisodes[i1]; i2++,id_++) {
                      long id = id_;
                      int season = i1+1;
                      int episode = i2;
                      int test =0;
                      Episode *e1 = new Episode(id,&seriesName,len,season,episode,tags);
                      content.push_back(e1);
                  }
              }
            }


}


void Session::route() {
    switch (s_mapStringValues[inputVector[0]]) {
        case CreateUser: //TBD
            std::cout<< "create user state"<< endl;
            break;
        case deleteUser:{ //TBD
            std::cout<< "delete user state"<< endl;
            DeleteUser *dl = new DeleteUser(); //create action from type deleteuser
            actionsLog.push_back(dl);
            dl->act(*this);
            mainLoop();
            break;}
        case changeActiveUser: //TBD
            std::cout<< "changeActiveUser state"<< endl;
            break;
        case DuplicateUser: //TBD
            std::cout<< "DuplicateUser state"<< endl;
            break;
        case Exit: //TBD
            std::cout<< "Exit state"<< endl;
            break;
        case PrintActionsLog: //TBD
            std::cout<< "PrintActionsLog state"<< endl;
            break;
        case PrintContentList: //TBD
            std::cout<< "PrintContentList state"<< endl;
            break;
        case PrintWatchHistory: //TBD
            std::cout<< "PrintWatchHistory state"<< endl;
            break;
        case Watch: //TBD
            std::cout<< "Watch state"<< endl;
            break;
    }
}

