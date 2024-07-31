
#pragma once

#include <string>
#include "Job.h"


using std::string;
class Character{

};

class Responsible : Character{

};

class Risktaking : Character{

};


class Player {
public:
    Player(string name, int level, int force, int current_HP, int Max_HP, int coins
           , string description, int power, Character character);

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

private:
    string name;
    int level;
    int force;
    int current_HP;
    int coins;
    string description;
    int max_HP;
    int power;
    Character character;
};

class Job : Player{

public:
    Job() {

    }
};

class Warrior : Job{
public:
    Warrior(string name, int level, int force, int current_HP, int Max_HP, int coins
            , string description,  int power);

};

class Archer : Job{
public:
    Archer(string name, int level, int force, int current_HP, int Max_HP, int coins
            , string description,  int power);

};

class Magician : Job{
public:
    Magician(string name, int level, int force, int current_HP, int Max_HP, int coins
            , string description,  int power);

};


