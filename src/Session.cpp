//
// Created by shachafk@wincs.cs.bgu.ac.il on 19/11/2019.
//
using namespace std;


#include <fstream>
#include "../include/Session.h"
#include "../include/json.hpp"
#include "../include/Watchable.h"

//Session constructor
Session::Session(const std::string &configFilePath):content(),actionsLog(),userMap({{ "default", activeUser }}),activeUser(){
    this->loadContents(configFilePath); //load all available contents from the json file to content vector
}
Session::~Session(){
    for (int i=0; i< content.size(); i++) {
        if (content[i] != nullptr)
            delete (content[i]);
    }
};
void Session::start(){ //this method should initialize default user with alg len recommendation then wait for the user to enter an action to execute
    cout<<"SPLFLIX is now on!"<<endl;
}


//getters
std::vector<Watchable*> *Session::getContent(){
    return &content;
}

//Rule of 3/5 TBD


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


