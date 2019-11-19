//
// Created by shachafk@wincs.cs.bgu.ac.il on 19/11/2019.
//
using namespace std;
#include "../include/Session.h"

Session::Session(const std::string &configFilePath):content(),actionsLog(),userMap({{ "default", activeUser }}),activeUser(){};
Session::~Session(){};
void start(){
    cout<<"SPLFLIX is now on!"<<endl;
}

