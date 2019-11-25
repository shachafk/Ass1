//
// Created by amitmich@wincs.cs.bgu.ac.il on 21/11/2019.
#include "../include/User.h"
#include "../include/Watchable.h"
#include "../include/Session.h"


//Rule of 3/5 TBD



RerunRecommenderUser::RerunRecommenderUser(const std::string& name):User(name){ Lastid =-1;};
Watchable* RerunRecommenderUser::getRecommendation(Session& s) {
    std::vector<Watchable *> hist = get_history();
    Watchable *last = hist[hist.size() - 1];
    if (last->getType() == 1) {//Movie
        return findRerRecomendation(); //by rerun recommendation
    } else if (last->getType() == 2) {//Episode
        Episode *curr = (Episode *) last;
        if (curr->getNextEpisodeId() != 0) {
            return s.getContent()[curr->getNextEpisodeId()]; //if there is next episode recommend on it
        } else {

            return findRerRecomendation();
            {
                //by rerun recommendation
            }
        }

        return nullptr;
    }
}
Watchable* RerunRecommenderUser::findRerRecomendation() {
    std::vector<Watchable *> hist = get_history();//get user's history vector
    if (hist.size()==0){ //
        return nullptr;
    }
    else{
        if(Lastid=-1){
        Lastid=Lastid+1;
        return hist.at(0);
        }
        else{
        Lastid=Lastid+1;
        return hist.at((Lastid) % hist.size());
        }
    }
}

