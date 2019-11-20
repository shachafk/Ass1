//
// Created by shachafk@wincs.cs.bgu.ac.il on 18/11/2019.
//

#ifndef WATCHABLE_H_
#define WATCHABLE_H_

#include <string>
#include <vector>


class Session;

class Watchable{
public:
    Watchable(long id, int length, const std::vector<std::string>& tags);
    Watchable(const Watchable &Watchable);
    virtual ~Watchable();
    virtual std::string toString() const = 0;
    virtual Watchable* getNextWatchable(Session&) const = 0;
    virtual long getId() const =0;
    virtual int getLength() const =0;
    virtual std::vector<std::string>& getTag() const =0;

private:
    const long id;
    int length;
    std::vector<std::string> tags;

};

class Movie : public Watchable{
public:
    Movie(long id, const std::string *name, int length, const std::vector<std::string>& tags);
    Movie(const Movie &Movie);
    virtual std::string toString(bool print_full=false) const;
    virtual Watchable* getNextWatchable(Session&) const;
    virtual std::string getName();
private:
    std::string name;

    std::string toString() const;

};


class Episode: public Watchable{
public:
    Episode(long id, const std::string& seriesName,int length, int season, int episode ,const std::vector<std::string>& tags);
    virtual std::string toString(bool print_full=false) const;
    virtual Watchable* getNextWatchable(Session&) const;
private:
    std::string seriesName;
    int season;
    int episode;
    long nextEpisodeId;

    const std::string &getseriesName();

    std::string toString() const;

    int getSeason();

    int getEpisode();
};

#endif