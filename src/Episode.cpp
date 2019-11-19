// Created by amitmich@wincs.cs.bgu.ac.il on 19/11/2019.
#include "../include/Watchable.h"
using namespace std;


    Episode::Episode(long _id, const string& _seriesName,int _length, int _season, int _episode ,const vector<std::string>& _tags):id(_id),seriesName(_seriesName),length(__length),season(_season),episode(_episode),tags(_tags){}
    std::string Episode::toString(bool print_full) const{ return this->seriesName;}//returns Series name
    Watchable* Episode::getNextWatchable(Session&) const{
        //if(nextEpisodeId!= nullptr)
        return nullptr; //&this.nextEpisodeId;//to implement
    }
    string seriesName;
    int season;
    int episode;
    long nextEpisodeId;







