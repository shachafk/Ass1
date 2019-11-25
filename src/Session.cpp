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
    setActiveUser(l);
    this->loadContents(configFilePath); //load all available contents from the json file to content vector
    s_mapStringValues.insert(std::make_pair("defaultcase", StringValue::defaultcase));
    s_mapStringValues.insert(std::make_pair("createuser", StringValue::createUser));
    s_mapStringValues.insert(std::make_pair("changeactiveuser", StringValue::changeActiveUser));
    s_mapStringValues.insert(std::make_pair("deleteuser", StringValue::deleteUser));
    s_mapStringValues.insert(std::make_pair("duplicateuser", StringValue::duplicateUser));
    s_mapStringValues.insert(std::make_pair("exit", StringValue::exit));
    s_mapStringValues.insert(std::make_pair("printactionslog", StringValue::printActionsLog));
    s_mapStringValues.insert(std::make_pair("printcontentlist", StringValue::printContentList));
    s_mapStringValues.insert(std::make_pair("printwatchhistory", StringValue::printWatchHistory));
    s_mapStringValues.insert(std::make_pair("watch", StringValue::watch));
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

void Session::setActiveUser(User* user){
    activeUser= user;
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


//getters
std::vector<Watchable*> Session::getContent(){
    return content;
}
std::unordered_map<std::string,User*>* Session::getUsersMap(){
    return &userMap;
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
std::vector<Watchable*> Session::myHistory(){
    return activeUser->get_history();
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
        default : //if no other case match
            std::cout << "Invalid action" << endl;
            mainLoop();
            break;
        case createUser: { //TBD
            std::cout << "create user state" << endl;
            CreateUser *c = new CreateUser(); //creates action from type createuser
            actionsLog.push_back(c); //save record of the action
            c->act(*this);
            mainLoop();
            break;
        }
        case deleteUser: {//TBD
            std::cout << "delete user state" << endl;
            DeleteUser *dl = new DeleteUser(); //creates action from type deleteuser
            actionsLog.push_back(dl);
            dl->act(*this);
            mainLoop();
            break;
        }
        case changeActiveUser: { //TBD
            std::cout << "changeActiveUser state" << endl;
            ChangeActiveUser *cau = new ChangeActiveUser(); //create action from type ChangeActiveUser
            actionsLog.push_back(cau);
            cau->act(*this);
            mainLoop();
            break;
        }
        case duplicateUser: //TBD
            std::cout << "DuplicateUser state" << endl;
            break;

        case exit: { //TBD
            std::cout << "Exit state" << endl;
            Exit *ex = new Exit(); //create action from type Exit
            ex->act(*this);
            actionsLog.push_back(ex);
            break;
        }
        case printActionsLog:{ //TBD
            std::cout<< "PrintActionsLog state"<< endl;
            PrintActionsLog *pal = new PrintActionsLog(); //create action from type PrintActionsLog
            pal->act(*this);
            actionsLog.push_back(pal);
            mainLoop();
            break;
        }
        case printContentList: { //TBD
            std::cout << "PrintContentList state" << endl;
            PrintContentList *pcl = new PrintContentList(); //create action from type PrintContentList
            pcl->act(*this);
            actionsLog.push_back(pcl);
            mainLoop();
            break;
        }

        case printWatchHistory: {
            std::cout<< "PrintWatchHistory state"<< endl;
            PrintWatchHistory *pwh = new PrintWatchHistory(); //create action from type printWatchHistory
            pwh->act(*this);
            actionsLog.push_back(pwh);
            mainLoop();
            break;
        }

        case watch: { //TBD
            std::cout << "Watch state" << endl;
            Watch *w = new Watch(); //create action from type Watch
            w->act(*this);
            actionsLog.push_back(w);
            mainLoop();
            break;
        }

    }
}


