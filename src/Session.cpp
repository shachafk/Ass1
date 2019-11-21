//
// Created by shachafk@wincs.cs.bgu.ac.il on 19/11/2019.
//
using namespace std;
#include <curses.h>
#include <fstream>
#include "../include/Session.h"
#include "../include/json.hpp"
#include "../include/Watchable.h"
#include "../include/User.h"
//Rule of 3/5 TBD
//Session constructor
Session::Session(const std::string &configFilePath):content(),actionsLog(),userMap(),activeUser(){
    const std::string &name = "default";
    LengthRecommenderUser *l = new LengthRecommenderUser(name);
    userMap.insert(std::make_pair(name,l));
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
std::unordered_map<std::string,User*> Session::getUsersMap(){
    return userMap;
}
std::vector<BaseAction*> Session::getActionsLog(){
    return actionsLog;
}
User* Session::getActiveUser(){
    return activeUser;
}

int Session::spaceLocator(char ch) // returns true if char is a space
{
    if(ch==' ')
        return 1;
    else return 0;
}

std::string Session::newActionScanner(std::istream &in){ // converts input stream to a string.
    printf("ENTER new action: ");
    clrscr();//waits for the user to form new action
    scanf("%[^\n]");
    std::string s(std::istreambuf_iterator<char>(cin), {});
    return s;
}
void Session::userCreate(std::string s) { //checks if action is "createuser" create new user and insert to user map
    std::string name = "";
    std::string type = "";
    name = s.substr(11, s.length() - 3);//TBD make sure it is the right use of substring
    type = s.substr(s.length() - 3);
    const std::string &name_=name;
    if (type=="len"){ // TBD to add other users types
        LengthRecommenderUser *u=new LengthRecommenderUser(name_);
        userMap.insert(std::make_pair(name,u));
    }
    else if (type=="rer"){
        RerunRecommenderUser *r=new RerunRecommenderUser(name_);
        userMap.insert(std::make_pair(name,r));
    }
    else if (type=="gen"){
        GenreRecommenderUser *g=new GenreRecommenderUser(name_);
        userMap.insert(std::make_pair(name,g));
    }
    else cout<<"invalid recommendtiontype"<<endl;
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


