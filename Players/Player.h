
#pragma once

#include <string>
#include "Charachter.h"
using std::string;
#include <memory>
using std::unique_ptr;
const int INITIAL_LEVEL = 1;
const int INITIAL_COINS = 10;
const int INITIAL_FORCE = 5;
const int INITIAL_MAXHP = 100;
const int MAX_LEVEL = 10;
const int MIN_FORCE = 0;

class Player {
protected:
   const string name;
   int level;
   int force;
   int current_HP;
   int max_HP;
   int coins;
   unique_ptr<Character> character;






public:
    explicit Player(const string &name, unique_ptr<Character> character);
    Player(const string& name,const int& level,const int& force,const
    int& current_HP,const int& max_HP,const int& coins, unique_ptr<Character> character);
    Player(const Player &other);
    virtual ~Player() = default;
    virtual Player* clone() const = 0;
    Player &operator=(const Player &other);


    virtual string getDescription() const = 0;

    string getName() const;
    virtual int getLevel() const;
    virtual int getForce() const;
    virtual int getHealthPoints() const;
    virtual int getCoins() const;

    virtual int getCombatPower();


};







