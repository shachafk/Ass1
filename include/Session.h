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
    enum RecommendationType{len,rer,gen};

public:
    Session(const std::string &configFilePath);
    ~Session();
    void start();
    void loadContents (const std::string &configFilePath);
    //getters
    std::vector<Watchable*> *getContent();
    std::unordered_map<std::string,User*> getUsersMap();
    std::vector<BaseAction*> getActionsLog();
    User* getActiveUser();
    int spaceLocator(char ch);
    std::vector <std::string>* getInputVector();

private:
    std::vector<Watchable*> content;
    std::vector<BaseAction*> actionsLog;
    std::unordered_map<std::string,User*> userMap;
    User* activeUser;
    std::vector<std::string> inputVector;
    std::map<std::string, StringValue> s_mapStringValues;
    void route();

    void mainLoop();

};
#endif