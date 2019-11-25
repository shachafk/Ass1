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

User* LengthRecommenderUser::clone(std::string name_) {
    LengthRecommenderUser *other=new LengthRecommenderUser(name_);
    other->copyHistory(get_history());
    other->copyAvailable(getAvailable());
    return other;
}


    int LengthRecommenderUser::findAveragelength(){
    //calculates average length of history
    std::vector<Watchable *> hist = get_history();
    int sum=0;
    for(int i=0;i<hist.size();i++){
        sum=sum+hist.at(i)->getLength();
    }
    return sum/hist.size();
}


 Watchable* LengthRecommenderUser::LengthRecommenderUser::getRecommendation(Session& s) {
     Watchable* toReturn = nullptr;
     int average = findAveragelength(); // get the average length from history
     std::map<long, Watchable*>::iterator it;
     int diff = average; 
     for (it = getAvailable()->begin(); it != getAvailable()->end(); it++){ //go over all content in available and check who as the smallest diff from average
         int temp = abs((*it).second->getLength() - average);
         if ( temp < diff){
             diff = temp;
             toReturn = (*it).second;
         }
     }

     return toReturn;
 }



