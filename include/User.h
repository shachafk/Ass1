//
// Created by shachafk@wincs.cs.bgu.ac.il on 18/11/2019.
//

#ifndef USER_H_
#define USER_H_

#include <vector>
#include <string>
#include <unordered_set>
#include <unordered_map>
#include <map>

class Watchable;
class Session;

class User{


public:
    User(const std::string& name);
    User(const User& other); //copy constructor
    virtual ~User();
    virtual Watchable* getRecommendation(Session& s) = 0;
    std::string getName() const;
    std::vector<Watchable*> get_history() const;
    void addToHistory(Watchable* toAdd);
    virtual User* clone() const = 0;
    void copyHistory(std::vector<Watchable *> hist);
    void copyTags(std::map<std::string, int> toCopy);

    void copyAvailable(std::map<long, Watchable*>* toCopy);
    void loadAvailable(Session& s);
    // getters
    std::map<long, Watchable*>* getAvailable()  ;
    std::map<std::string, int>* getSorted()  ;


protected:
    std::vector<Watchable*> history;
private:
     std::string name;
     std::map<long, Watchable*> available;
     std::map<std::string, int> sortedTags;

};


class LengthRecommenderUser : public User {
public:
    LengthRecommenderUser(const std::string& name);
    virtual Watchable* getRecommendation(Session& s);

    virtual User* clone() const ;

private:
    int findAveragelength();
};

class RerunRecommenderUser : public User {
public:
    RerunRecommenderUser(const std::string& name);
    RerunRecommenderUser(const RerunRecommenderUser& other); //copyconstructor
    virtual Watchable* getRecommendation(Session& s);

    virtual User* clone() const;

private:
    int Lastid;

};

class GenreRecommenderUser : public User {
public:
    GenreRecommenderUser(const std::string& name);
    virtual Watchable* getRecommendation(Session& s);

    Watchable* findBestContent(std::string max,Session& s);

    virtual User* clone() const ;
private:
};

#endif