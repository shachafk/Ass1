//
// Created by amitmich@wincs.cs.bgu.ac.il on 21/11/2019.
//
#include "../include/User.h"

//Rule of 3/5 TBD

GenreRecommenderUser::GenreRecommenderUser(const std::string& name):User(name){};
User* GenreRecommenderUser::clone(std::string name_) {
    GenreRecommenderUser *other=new GenreRecommenderUser(name_);
    other->copyHistory(get_history());
    other->copyAvailable(getAvailable());
    return other;
}
 Watchable* GenreRecommenderUser::getRecommendation(Session& s){
 /*    std::vector<Watchable *> hist = get_history();//get user's history vector
     std::map<long, Watchable*>* avilable =  getAvailable();
     std::vector<std::string,int> sortedTags;
     int maxcount=0;
     std::string temp;
     std::vector<Watchable *>::iterator it;
     for(it = hist.begin();it!=hist.end();it++) { //go over the user's history
         const std::vector<std::string> &tags = (*it).getTag(); //check it TBD
         for (int i = 0; i < tags.size(); i++) { //go over each tag
             std::string curr = tags.at(i);
             std::vector<int>::iterator it = std::find(sortedTags.begin(), sortedTags.end(), curr)
             if (it != sortedTags.end()) {
                 it->second++;
             } else {
                 sortedTags.push_back(std::make_pair(curr, 1));
             }
         }
     }


     /*        for (int i = 0; i < getTag().size; i++)
                 for (int j = i + 1; j < getTag().size; j++) {
                     if (tags.at(i) > tags.at(j)) {
                         temp = tags.at(i);
                         tags.at(i) = tags.at(j);
                         tags.at(j) = temp;
                     }
*/


      //       }

     return nullptr;}

