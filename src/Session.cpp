//
// Created by shachafk@wincs.cs.bgu.ac.il on 19/11/2019.
//
using namespace std;


#include <fstream>
#include "../include/Session.h"
#include "../include/json.hpp"
#include "../include/Watchable.h"

Session::Session(const std::string &configFilePath):content(),actionsLog(),userMap({{ "default", activeUser }}),activeUser(){this->loadContents(configFilePath);}//
Session::~Session(){};
void Session::start(){
    cout<<"SPLFLIX is now on!"<<endl;
}

void Session::loadContents (const std::string &configFilePath) {
    std::ifstream i(configFilePath);
    nlohmann::json j;
    i >> j;
    int id = 0;
    for (nlohmann::json::iterator itr = j.begin(); itr != j.end(); itr++) {
        if (itr.key() == "movies") {
            for (int i = id; i < j["movies"].size(); i++) {
                long id = i;
                const string name = j["movies"][i]["name"];
                int len = j["movies"][i]["length"];
                const std::vector<std::string> tags = j["movies"][i]["tags"];
               // std::cout << id << endl;
               // std::cout << name << endl;
               // std::cout << len << endl;
//                Movie m(id,&name,len,tags);
                //std::cout<<&m<<endl;
 //               content.push_back(m);
            }

            if (itr.key() == "tv_series") {


            }


        }
    }}



