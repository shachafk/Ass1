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
    Watchable(Watchable& Watchable); //copy constructor
    virtual ~Watchable(); //destructor
    virtual std::string toString() const = 0;
    virtual Watchable* getNextWatchable(Session& s) const = 0;
    void copy(Watchable &Watchable);
    void clean();
    virtual Watchable* clone() const = 0;
    virtual std::string printContent() = 0;

    //getters
    long getId() const;
    int  getLength() const ;
    const std::vector<std::string> & getTag() const;


private:
    long id;
    int length;
    std::vector<std::string> tags;

};

class Movie : public Watchable{
public:
    Movie(long id, const std::string &name, int length, const std::vector<std::string>& tags);
    Movie(const Movie &Movie);
    virtual std::string toString() const;
    virtual Watchable* getNextWatchable(Session& s) const;
    virtual std::string getName() const;
    virtual Watchable* clone() const;
    virtual std::string printContent();
private:
    std::string name;
};


class Episode: public Watchable{
public:
    Episode(long id, const std::string &seriesName, int length, int season, int episode , const std::vector<std::string>& tags);
    Episode(const Episode& other); //copy constructor
    virtual std::string toString() const;
    virtual Watchable* getNextWatchable(Session& s) const;
    std::string getSeriesName() const;
    int getSeason() const;
    int getEpisode() const;
    void setNextId(long i);
    long getNextEpisodeId() const;
    virtual Watchable* clone() const;
    virtual std::string printContent();
private:
    std::string seriesName;
    int season;
    int episode;
    long nextEpisodeId;

  //  const std::string &getseriesName();


};

#endif