
#pragma once

#include <string>
#include "Job.h"
using std::string;
#include <memory>
using std::unique_ptr;

class Character{

};

class Responsible : public Character{

};

class Risktaking : public Character{

};

class Job{

public:
    Job();
};

class Warrior : Job{
public:
    Warrior();

};

class Archer : Job{
public:
    Archer();


};

class Magician : Job{
public:
    Magician();

};


class Player {
protected:
   const  string name;
   int level;
   int force;
   int current_HP;
   int max_HP;
   int coins;
   unique_ptr<Character> character;
   unique_ptr<Job> job;

public:
    Player(const string& name, int level, int force, int current_HP, int max_HP, int coins
           , Character* character ,Job*  job); //character(std::move(character))
    ~Player();

    void setCharachter(Character* character);

    void setJob(Job* job);



    /**
     * Gets the description of the player
     *
     * @return - description of the player
    */
    string getDescription() const;

    /**
     * Gets the name of the player
     *
     * @return - name of the player
    */
    string getName() const;

    /**
     * Gets the current level of the player
     *
     * @return - level of the player
    */
    int getLevel() const;

    /**
     * Gets the of force the player has
     *
     * @return - force points of the player
    */
    int getForce() const;

    /**
     * Gets the amount of health points the player currently has
     *
     * @return - health points of the player
    */
    int getHealthPoints() const;

    /**
     * Gets the amount of coins the player has
     *
     * @return - coins of the player
    */
    int getCoins() const;
};



