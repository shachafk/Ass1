//
// Created by amitmich@wincs.cs.bgu.ac.il on 19/11/2019.
//
#include "../include/User.h"
#include "../include/Watchable.h"
#include "../include/Session.h"
#include <stdlib.h>



//Rule of 3/5 TBD


LengthRecommenderUser::LengthRecommenderUser(const std::string& name):User(name){
};

void User::loadAvailable(Session& s){ //load all content from content vector to map
    for (int i=1; i < s.getContent().size(); i++){
        available.insert(std::make_pair(s.getContent().at(i)->getId(),s.getContent().at(i)));
    }
}


 Watchable* LengthRecommenderUser::LengthRecommenderUser::getRecommendation(Session& s) {
     //calculates average length of history
     std::vector<Watchable *> hist = get_history();
     int sum=0;
     for(int i=0;i<hist.size();i++){
         sum=sum+hist.at(i)->getLength();
     }
     int averege=sum/hist.size();

     std::map<long, Watchable*>::iterator it;
     int diff = averege;
     Watchable* toReturn = nullptr;
     for (it = getAvailable()->begin(); it != getAvailable()->end(); it++){
         int temp = abs((*it).second->getLength() - averege);
         if ( temp < diff){
             diff = temp;
             toReturn = (*it).second;
         }
     }

     return toReturn;
 }



