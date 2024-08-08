
#pragma once

#include <string>
#include "Character.h"
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
   string outcome;






public:
    explicit Player(const string &name, unique_ptr<Character> character);
    Player(const string& name,const int& level,const int& force,const
    int& current_HP,const int& max_HP,const int& coins, unique_ptr<Character> character);
    Player(const Player &other);
    virtual ~Player() = default;
    virtual std::unique_ptr<Player> clone() const = 0;
    Player &operator=(const Player &other);


    virtual string getDescription() const = 0;

    string getName() const;
    virtual int getLevel() const;
    virtual int getForce() const;
    virtual int getHealthPoints() const;
    virtual int getCoins() const;
    string getCharacter() const;
    int getCurrentHP() const;
    virtual int getMaxHP() const;

    virtual void setForce(const int& force);
    virtual void addCurrentHP(const int& hp);
    virtual void decreaseCurrentHP(const int& damage);

    virtual void Weaken(const int& hp) = 0;


    //additional helping functions

    /* checks if player can pay a certain amount if so it takes the coins and return
     true otherwise it returns false */
    bool canPlayerPay(int coins) const;

    /* checks if player's health points can be raised without exceeding max_hp */
    bool check_adding_HP(int hp) const;

    void levelUp(); // adds one level if it exceed 10 it stays 10;

    virtual int getCombatPower();

    void addCoins(int coins);

    void decreaseCoins(int coins);

    virtual string getJob() const = 0;

    virtual void checkOutCome(const string& outcome);

    virtual string getOutCome();

};







