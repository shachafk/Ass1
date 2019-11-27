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
    Watchable(Watchable& Watchable);
    virtual ~Watchable();
    virtual std::string toString() const = 0;
    virtual Watchable* getNextWatchable(Session& s) const = 0;
    void copy(Watchable &Watchable);
    void clean();
    virtual Watchable* clone() = 0;
    void setType (int i);

    //getters
    long getId() const;
    int  getLength() const ;
    virtual int getType() const ;
    const std::vector<std::string> & getTag() const;


private:
    long id;
    int length;
    std::vector<std::string> tags;
    int type; //Movie=1, Episode =2

};

class Movie : public Watchable{
public:
    Movie(long id, const std::string &name, int length, const std::vector<std::string>& tags);
    Movie(const Movie &Movie);
    virtual std::string toString() const;
    virtual Watchable* getNextWatchable(Session& s) const;
    virtual std::string getName() const;
    virtual Watchable* clone();
private:
    std::string name;

    //std::string toString() const;

};


class Episode: public Watchable{
public:
    Episode(long id, const std::string &seriesName, int length, int season, int episode , const std::vector<std::string>& tags);
    virtual std::string toString() const;
    virtual Watchable* getNextWatchable(Session& s) const;
    std::string getseriesName() const;
    int getSeason() const;
    int getEpisode() const;
    void setNextId(long i);
    long getNextEpisodeId() const;
    virtual Watchable* clone();
private:
    std::string seriesName;
    int season;
    int episode;
    long nextEpisodeId;

  //  const std::string &getseriesName();


};

#endif