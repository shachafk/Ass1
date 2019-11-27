// Created by amitmich@wincs.cs.bgu.ac.il on 19/11/2019.
#include "../include/Watchable.h"
#include "../include/Session.h"
#include "../include/User.h"

using namespace std;


//Rule of 3/5 TBD


    Episode::Episode(long id, const std::string &seriesName, int length, int season, int episode , const std::vector<std::string>& tags) :Watchable(id,length,tags),seriesName(seriesName),season(season),episode(episode){
        setType(2);
    }

    Episode::Episode(const Episode& other):Watchable((Watchable &) other), seriesName(other.seriesName) , season(other.episode), episode(other.episode), nextEpisodeId(other.nextEpisodeId){} //copy constructor


Watchable* Episode::clone() const { return new Episode(*this);}


std::string Episode::toString() const{
        std::vector<std::string> tag = getTag(); //prepare the tag string
        std::string tagString = "[";
        for (int i=0;(unsigned)i<tag.size();i++){
            if (i>0){
                tagString = tagString + ",";
            }
            tagString = tagString + tag.at(i);
        }
        tagString = tagString + "]";
        std::string toReturn;
        std::string SE; //season
        if (getSeason()<10){
            SE = "0" + std::to_string(getSeason());
        }
        else {
            SE = std::to_string(getSeason());
        }
        std::string EP; //episode
        if (getEpisode()<10){
            EP = "0" + std::to_string(getEpisode());
        }
        else {
            EP = std::to_string(getEpisode());
        }
        toReturn = std::to_string(getId()) + ". " +  getseriesName() + " S" + SE + "E" + EP + " " +
                std::to_string(getLength())+ " minutes " + tagString;

        return toReturn;
    }

    Watchable* Episode::getNextWatchable(Session& s) const{

            if (getNextEpisodeId() != 0) {
                return s.getContent()[getNextEpisodeId()]; //if there is next episode recommend on it
            } else {
                return s.getActiveUser()->getRecommendation(s); //by  recommendation
            }
    }
//     std::string Episode::toString() const {return "";}
    //getters
    std::string Episode::getseriesName() const {
        return seriesName ;
    }
    int Episode:: getSeason() const{
        return this->season ;
    }

    int Episode:: getEpisode() const{
        return this->episode ;
    }

long Episode::getNextEpisodeId() const {
        return nextEpisodeId;
    }


//setters
    void Episode::setNextId(long i){
        nextEpisodeId = i;
    }







