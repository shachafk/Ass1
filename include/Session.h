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

enum StringValue {changeActiveUser,
    CreateUser,
    DeleteUser,
    DuplicateUser,
    Exit,
    PrintActionsLog,
    PrintContentList,
    PrintWatchHistory,
    Watch};


class Session{
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