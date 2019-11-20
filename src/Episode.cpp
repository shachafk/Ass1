// Created by amitmich@wincs.cs.bgu.ac.il on 19/11/2019.
#include "../include/Watchable.h"
using namespace std;


    Episode::Episode(long id, const string& seriesName,int length, int season, int episode ,const vector<std::string>& tags,long nextEpisodeId):Watchable(id,length,tags),seriesName(seriesName),season(season),episode(episode),nextEpisodeId(0){}
    std::string Episode::toString(bool print_full) const{ return this->seriesName;}//returns Series name
    Watchable* Episode::getNextWatchable(Session&) const{
        //if(nextEpisodeId!= nullptr)
        return nullptr; //&this.nextEpisodeId;//to implement
    }
     std::string Episode::toString() const {return "";}
    //getters
    const string& Episode:: getseriesName(){
        return seriesName ;
    }
    int Episode:: getSeason(){
        return season ;
    }

    int Episode:: getEpisode(){
        return episode ;
    }






