//
// Created by amitmich@wincs.cs.bgu.ac.il on 21/11/2019.
#include "../include/User.h"
#include "../include/Watchable.h"
#include "../include/Session.h"


//Rule of 3/5 TBD



RerunRecommenderUser::RerunRecommenderUser(const std::string& name):User(name){ Lastid =-1;};
User* RerunRecommenderUser::clone(std::string name_) {
    RerunRecommenderUser *other=new RerunRecommenderUser(name_);
    other->copyHistory(get_history());
    other->copyAvailable(getAvailable());
    other->copyTags(*getSorted());
    return other;
}
Watchable* RerunRecommenderUser::getRecommendation(Session& s) {
    std::vector<Watchable *> hist = get_history();//get user's history vector
    if (hist.size()==0){ //in case no history
        return nullptr;
    }
    else{

        if(Lastid==-1){
            Lastid=0;
            return hist.at(0);
        }
        else{
            long newId = (Lastid+1) % hist.size();
            Lastid = newId;
            return hist.at(newId);
        }
    }

    }

