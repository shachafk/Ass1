//
// Created by amitmich@wincs.cs.bgu.ac.il on 19/11/2019.
//
#include "../include/User.h"
#include "../include/Watchable.h"
#include "../include/Session.h"



//Rule of 3/5 TBD


LengthRecommenderUser::LengthRecommenderUser(const std::string& name):User(name){};

 Watchable* LengthRecommenderUser::LengthRecommenderUser::getRecommendation(Session& s) {
     //calculates avereage length of history
     std::vector<Watchable *> hist = get_history();
     int sum=0;
     for(int i=1;i<hist.size();i++){
         sum=sum+hist.at(i)->getLength();
     }
     int averege=sum/hist.size()-1;

     return nullptr;

 }



