
#pragma once

#include <string>
#include "Job.h"
using std::string;
#include <memory>
using std::unique_ptr;

class Character{
public:
    virtual ~Character() = default;
    virtual string getDescription() const = 0;

};

class Responsible : public Character{
public:
    string getDescription() const override;
};

class Risktaking : public Character{
public:
    string getDescription() const override;
};

class Job{

public:
    Job() = default;
    virtual ~Job() = default;
    virtual string getDescription() const = 0;
};

class Warrior : Job{
public:
    Warrior();
    string getDescription() const override;

};

class Archer : Job{
public:
    Archer();
    string getDescription() const override;


};

class Magician : Job{
public:
    Magician();
    string getDescription() const override;

};


class Player {
protected:
   const string name;
   int level;
   int force;
   int current_HP;
   int max_HP;
   int coins;
   unique_ptr<Character> character;
   unique_ptr<Job> job;

public:
    Player(const string& name, int level, int force, int current_HP, int max_HP, int coins,
           Character* character, Job* job);

    ~Player() = default;

    void setCharachter(Character* character);

    void setJob(Job* job);

   string getDescription() const;

    string getName() const;

    int getLevel() const;

    int getForce() const;

    int getHealthPoints() const;

    int getCoins() const;

};



