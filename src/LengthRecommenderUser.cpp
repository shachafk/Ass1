//
// Created by amitmich@wincs.cs.bgu.ac.il on 19/11/2019.
//
#include "../include/User.h"
#include "../include/Watchable.h"
#include "../include/Session.h"



//Rule of 3/5 TBD


LengthRecommenderUser::LengthRecommenderUser(const std::string& name):User(name){};

 Watchable* LengthRecommenderUser::LengthRecommenderUser::getRecommendation(Session& s) {
     std::vector<Watchable*> hist = get_history();
     Watchable* last = hist[hist.size()-1];
     if ( last->getType() == 1) {//Movie
         return findLenRecomendation(); //by len recommendation
     }

     else if (last->getType() ==2) {//Episode
         Episode *curr = (Episode *) last;
         if (curr->getNextEpisodeId() != 0) {
             return s.getContent()[curr->getNextEpisodeId()]; //if there is next episode reccomend on it
         } else {

             return findLenRecomendation(); //by len recommendation
         }
     }




     return nullptr;
 }

Watchable* LengthRecommenderUser::findLenRecomendation(){

 }

