//
// Created by amitmich@wincs.cs.bgu.ac.il on 21/11/2019.
//
#include "../include/User.h"
#include "../include/Session.h"
#include "../include/Watchable.h"
#include <algorithm>




GenreRecommenderUser::GenreRecommenderUser(const std::string& name):User(name){};


    User* GenreRecommenderUser::clone() const {
    return new GenreRecommenderUser(*this);
}
 Watchable* GenreRecommenderUser::getRecommendation(Session& s){
     std::map<std::string, int>* map= s.getActiveUser()->getSorted();
     if (map->size()==0){ //if no more tags to watch
         return nullptr;
     }
     int maxvalue=0;
     std::string max;
     std::map<std::string, int>::iterator iter;
     for(iter=map->begin();iter!=map->end();iter++){//finds tag w max repetitions
         if((*iter).second>maxvalue)
             max=(*iter).first;
     }
     return findBestContent(max,s);
}

Watchable* GenreRecommenderUser::findBestContent(std::string max,Session& s){//go over available and finds content with max tag
    std::map<long, Watchable*>* available=getAvailable();
    std::map<long, Watchable*>::iterator it;
    for(it=available->begin();it!=available->end();it++) {
        Watchable* option = (*it).second;
        if (std::count(option->getTag().begin(),option->getTag().end(),max) > 0)
            return option;
    }
    getSorted()->erase(max); //if no more availble content of that tag erase that tag
    return getRecommendation(s);//go find next most popular tag
}



