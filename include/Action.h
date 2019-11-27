//
// Created by shachafk@wincs.cs.bgu.ac.il on 18/11/2019.
//

#ifndef ACTION_H_
#define ACTION_H_
#include <map>
#include <string>
#include <string>
#include <iostream>
#include "Watchable.h"

class Session;

enum ActionStatus{
    PENDING, COMPLETED, ERROR
};
enum RecommendationType{Default,len,gen,rer};


class BaseAction{
public:
    BaseAction();
    BaseAction(const BaseAction& other);
    virtual BaseAction* clone() const =0;
    virtual ~BaseAction();
    virtual void act(Session& sess)=0;
    virtual std::string toString() const=0;
    //getters
    std::string getEnumStringFromInt(int i) const;
    std::string getError() const ;
    ActionStatus getStatus() const;

protected:
    void complete();
    void error(const std::string& errorMsg);
    std::string getErrorMsg() const;
    std::map<std::string, RecommendationType> getEnumMap();


private:
    std::string errorMsg;
    ActionStatus status;
    std::string castEnumArray[3];
    std::map<std::string, RecommendationType> u_mapStringValues;

};

class CreateUser  : public BaseAction {
public:
    virtual void act(Session& sess);
    virtual std::string toString() const;
    virtual BaseAction *clone() const;
};

class ChangeActiveUser : public BaseAction {
public:
    virtual void act(Session& sess);
    virtual std::string toString() const;
    virtual BaseAction *clone() const;
};

class DeleteUser : public BaseAction {
public:
    virtual void act(Session & sess);
    virtual std::string toString() const;
    virtual BaseAction *clone() const;

};


class DuplicateUser : public BaseAction {
public:
    virtual void act(Session & sess);
    virtual std::string toString() const;
    virtual BaseAction *clone() const;

};

class PrintContentList : public BaseAction {
public:
    virtual void act (Session& sess);
    virtual std::string toString() const;
    virtual BaseAction *clone() const;

};

class PrintWatchHistory : public BaseAction {
public:
    virtual void act (Session& sess);
    virtual std::string toString() const;
    virtual BaseAction *clone() const;

};


class Watch : public BaseAction {
public:
    virtual void act(Session& sess);
    virtual std::string toString() const;
    void play(Watchable* watchable,Session& sess);
    virtual BaseAction *clone() const;

};


class PrintActionsLog : public BaseAction {
public:
    virtual void act(Session& sess);
    virtual std::string toString() const;
    virtual BaseAction *clone() const;

};

class Exit : public BaseAction { //exit command should only exit the main loop, all session data structure should remain
public:
    virtual void act(Session& sess);
    virtual std::string toString() const;
    virtual BaseAction *clone() const;

};
#endif