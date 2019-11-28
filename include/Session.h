//
// Created by shachafk@wincs.cs.bgu.ac.il on 18/11/2019.
//

#ifndef SESSION_H_
#define SESSION_H_

#include <vector>
#include <unordered_map>
#include <string>
#include <map>
#include "Action.h"

class User;
class Watchable;

class Session{
    enum StringValue {defaultcase,
        changeActiveUser,
        createUser,
        deleteUser,
        duplicateUser,
        exit,
        printActionsLog,
        printContentList,
        printWatchHistory,
        watch};

public:
    Session(const std::string &configFilePath);
    Session(const Session &other); //copy constructor
    Session& operator=(const Session& s); //copy assignment
    Session(Session &&other);//move
    Session& operator=(Session &&other);//move assignment
    void cleanOther(Session &other); //set all other pointers to null
    void copy(const Session& s) ;
    ~Session();
    void start();
    void loadContents (const std::string &configFilePath);//loads watchable contents from json
    //getters
    std::vector<Watchable*> getContent() const ;
    std::unordered_map<std::string,User*>* getUsersMap();
    std::vector<BaseAction*> getActionsLog() const ;
    User* getActiveUser() const ;
    std::vector <std::string>* getInputVector()  ;
    void setActiveUser(User* user);
    void runAction(BaseAction* action);//this method calls act,update actionslog and returns to main loop.
    void loadMapStringValues(); //this method cast action code for switch reserved word
    void watchAgain(BaseAction *action);//this method calls the watch act again in case the user chooses yes after recommendation.

private:
    std::vector<Watchable*> content;
    std::vector<BaseAction*> actionsLog;
    std::unordered_map<std::string,User*> userMap;
    User* activeUser;
    std::vector<std::string> inputVector;
    std::map<std::string, StringValue> s_mapStringValues;
    void route();// this method refers each action commend to the right class to be activated
    void clean();
    void mainLoop();// when that function called we can get a new action request
    void changeToNewPointer(User *u) const;//this method changes pointers of history to the matching content pointers by id in order to prevent

};
#endif