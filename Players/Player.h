
#pragma once

#include <string>
#include "Job.h"
#include "Charachter.h"
using std::string;
#include <memory>
using std::unique_ptr;


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



