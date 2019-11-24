// Created by amitmich@wincs.cs.bgu.ac.il on 19/11/2019.
#include "../include/Watchable.h"
using namespace std;


//Rule of 3/5 TBD


    Episode::Episode(long id, const std::string *seriesName, int length, int season, int episode , const std::vector<std::string>& tags) :Watchable(id,length,tags),seriesName(*seriesName),season(season),episode(episode){
        // next episode id - to implement

    }
    std::string Episode::toString() const{
        std::vector<std::string> tag = getTag(); //prepare the tag string
        std::string tagString = "[";
        for (int i=0;i<tag.size();i++){
            tagString = tagString + tag.at(i) + ",";
        }
        tagString = tagString + "]";

        std::string toReturn;
        toReturn = std::to_string(getId()) + getseriesName() + std::to_string(getLength()) + tagString;
        return toReturn;
    }

    Watchable* Episode::getNextWatchable(Session&) const{
        //if(nextEpisodeId!= nullptr)
        return nullptr; //&this.nextEpisodeId;//to implement
    }
//     std::string Episode::toString() const {return "";}
    //getters
    std::string Episode::getseriesName() const {
        return seriesName ;
    }
    int Episode:: getSeason(){
        return season ;
    }

    int Episode:: getEpisode(){
        return episode ;
    }






