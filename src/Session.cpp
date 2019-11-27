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

Session::Session(const std::string &configFilePath):content(),actionsLog(),userMap(),activeUser() {
    this->loadContents(configFilePath); //load all available contents from the json file to content vector
    const std::string &name = "default";
    LengthRecommenderUser *l = new LengthRecommenderUser(name);
    l->loadAvailable(*this);
    userMap.insert(std::make_pair(name, l));
    setActiveUser(l);
    loadMapStringValues();
}

// Rule of 5

Session &Session::operator=(const Session& s) { //copy assignment
    //check for self assignment
    if (this==&s){
        return *this;
    }
    else {
        clean();
        this->copy(s); // ?? TBD
        return *this; // ??
    }
}

Session::~Session(){ //destructor
  clean();
};

Session::Session(const Session &other) { //copy constructor
    loadMapStringValues();
    content.push_back(nullptr); //place 0
    for (int i=1;(unsigned)i<other.content.size();i++){ //copy content vector
        content.push_back(other.content.at(i)->clone());
    }
    for (int i=0;(unsigned)i<other.actionsLog.size();i++){ //copy actionsLog vector
        actionsLog.push_back(other.actionsLog.at(i)->clone());
    }
    for (int i=0;(unsigned)i<other.inputVector.size();i++){ //copy inputVector vector
        inputVector.push_back(other.inputVector.at(i));
    }
    std::string temp = other.activeUser->getName();

    for ( auto it = other.userMap.begin(); it != other.userMap.end() ;it++){ //copy userMap
        User* temp = (*it).second->clone();
        userMap.insert(std::make_pair((*it).first,temp));
        changeToNewPointer(temp);
    }

    activeUser = userMap[temp];
}

void Session::changeToNewPointer(User* u) const {
    for (int i=0; (unsigned) i< u->getHistory()->size(); i++){
        Watchable* temp = u->getHistory()->at(i);
        long id = temp->getId();
        u->getHistory()->at(i) = content.at(id);
    }
    for (auto it=u->getAvailable()->begin(); it!= u->getAvailable()->end();it++){
        Watchable* temp = (*it).second;
        long id = temp->getId();
        (*it).second = content.at(id);
    }

}
    void Session::copy(const Session& s) {
    content.push_back(nullptr);
    for (int i=1;(unsigned)i<s.content.size();i++){ //copy content vector
        content.push_back(s.content.at(i)->clone());
    }

    for (int i=0;(unsigned)i<s.actionsLog.size();i++){ //copy actionsLog vector
        actionsLog.push_back(s.actionsLog.at(i)->clone());
    }
    for (int i=0;(unsigned)i<s.inputVector.size();i++){ //copy inputVector vector
    inputVector.push_back(s.inputVector.at(i));
    }
    std::string temp = s.activeUser->getName();
    for ( auto it = s.userMap.begin(); it != s.userMap.end() ;it++){ //copy userMap
    userMap.insert(std::make_pair((*it).first,(*it).second->clone()));
    }
    activeUser = userMap[temp];
    s_mapStringValues = s.s_mapStringValues;
}



void Session::clean(){
    for (int i=0; (unsigned)i< content.size(); i++) { //delete all movie and episode from content vector
        if (content[i] != nullptr)
            delete (content[i]);
    }
    for (int i=0;(unsigned) i< actionsLog.size();i++){ //delete all logs from actionlog
        if (actionsLog[i] != nullptr)
            delete (actionsLog[i]);
    }
    for (auto it = userMap.begin();it!=userMap.end();it++ ){ //delete all users from usermap
        delete(it->second);
    }

    inputVector.clear();
    activeUser = nullptr;
    s_mapStringValues.clear();


}

    void Session::loadMapStringValues(){
        s_mapStringValues.insert(std::make_pair("defaultcase", StringValue::defaultcase));
        s_mapStringValues.insert(std::make_pair("createuser", StringValue::createUser));
        s_mapStringValues.insert(std::make_pair("changeuser", StringValue::changeActiveUser));
        s_mapStringValues.insert(std::make_pair("deleteuser", StringValue::deleteUser));
        s_mapStringValues.insert(std::make_pair("dupuser", StringValue::duplicateUser));
        s_mapStringValues.insert(std::make_pair("exit", StringValue::exit));
        s_mapStringValues.insert(std::make_pair("log", StringValue::printActionsLog));
        s_mapStringValues.insert(std::make_pair("content", StringValue::printContentList));
        s_mapStringValues.insert(std::make_pair("watchhist", StringValue::printWatchHistory));
        s_mapStringValues.insert(std::make_pair("watch", StringValue::watch));
    }


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
    iss.clear();
    route();
}


//getters
std::vector<Watchable*> Session::getContent() const {
    return content;
}
std::unordered_map<std::string,User*>* Session::getUsersMap() {
    return &userMap;
}

std::vector<BaseAction*> Session::getActionsLog() const{
    return actionsLog;
}
User* Session::getActiveUser() const{
    return activeUser;
}
    std::vector<std::string>* Session::getInputVector() {
    return &inputVector;
}
std::vector<Watchable*> Session::myHistory() const{
    return activeUser->get_history();
}
void Session::setActionInLog(BaseAction* act){
    actionsLog.push_back(act);
}



void Session::loadContents (const std::string &configFilePath) {
    std::ifstream i(configFilePath);
    nlohmann::json j;
    i >> j;
    long id_ = 1;
    content.push_back(nullptr); // place 0 will be empty
    // go over all movies and insert each movie to content vector
            for (int i = 0; (unsigned)i < j["movies"].size(); i++,id_++) {
                long id = id_;
                const string name = j["movies"][i]["name"];
                int len = j["movies"][i]["length"];
                const std::vector<std::string> tags = j["movies"][i]["tags"];
                Movie *m1 = new Movie(id, name, len, tags);
                content.push_back(m1);
            }
    // go over all tv series and insert all episodes to content vector
            for (int i = 0; (unsigned)i < j["tv_series"].size(); i++) {
               int len = j["tv_series"][i]["episode_length"];
               const std::vector<std::string> tags = j["tv_series"][i]["tags"];
               const string seriesName  = j["tv_series"][i]["name"];
               const std::vector<int> numOfEpisodes = j["tv_series"][i]["seasons"];

              for ( int i1=0;(unsigned)i1< numOfEpisodes.size();i1++){ //for each seasons create all episodes
                  for (int i2=1; i2<= numOfEpisodes[i1]; i2++,id_++) { //i1 se , i2 ep
                      long id = id_;
                      int season = i1+1;
                      int episode = i2;
                      Episode *e1 = new Episode(id,seriesName,len,season,episode,tags);

                      if (i2 < numOfEpisodes[i1]){
                          e1->setNextId(id+1); //there is next ep in the same se
                      }
                      else if (i2== numOfEpisodes[i1] and (unsigned) i1 < numOfEpisodes.size()-1){
                          e1->setNextId(id+1); //This is the last ep on the se but there is a new se
                      }
                      else {
                          e1->setNextId(0);
                      }
                      content.push_back(e1);
                  }
              }
            }


}

void Session::watchAgain(BaseAction* action){
    actionsLog.push_back(action); //save record of the action
    action->act(*this);
}

void Session::runAction(BaseAction* action){
    actionsLog.push_back(action); //save record of the action
    action->act(*this);
    mainLoop();
}

void Session::route() {
    if (inputVector.size()==0)
       inputVector.push_back("default");
    switch (s_mapStringValues[inputVector[0]]) {
        default : //if no other case match
            std::cout << "Invalid action" << endl;
            mainLoop();
            break;
        case createUser: { //TBD
            runAction(new CreateUser());
            break;
        }
        case deleteUser: {//TBD
            runAction(new DeleteUser());
            break;
        }
        case changeActiveUser: { //TBD
            runAction(new ChangeActiveUser());
            break;
        }
        case duplicateUser: //TBD
            runAction(new DuplicateUser());
            break;

        case exit: { //TBD
            Exit* ex = new Exit();
            actionsLog.push_back(ex); //save record of the action
            ex->act(*this);
            return;
        }
        case printActionsLog:{ //TBD
            PrintActionsLog* pal = new PrintActionsLog();
            pal->act(*this);
            actionsLog.push_back(pal); //save record of the action
            mainLoop();
            break;
        }
        case printContentList: { //TBD
            runAction(new PrintContentList());
            break;
        }

        case printWatchHistory: {
            runAction(new PrintWatchHistory());
            break;
        }

        case watch: { //TBD
            runAction(new Watch());
            break;
        }

    }
}


