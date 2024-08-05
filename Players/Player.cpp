#include "Player.h"

#include "Utilities.h"
#include "Charachter.h"
#include "Job.h"
#include "string"
#include <utility>
#include <vector>

Player::Player(const string &name) : name(name), level(INITIAL_LEVEL), force(INITIAL_FORCE)
        ,current_HP(INITIAL_MAXHP),max_HP(INITIAL_MAXHP),coins(INITIAL_COINS){}


Player::Player(const string &name,const int &level,const int &force,const int &current_HP,
               const int &max_HP,const int &coins):
        name(name), level(level), force(force), current_HP(current_HP), max_HP(max_HP), coins(coins) {}

string Player:: getDescription() const{
    string os = this->getName() + ", " + this->job->getDescription() + "with"
            + this->character->getDescription() + "character (level" +
            this->level + " ,force" + this->force + ")";
    return os;
}

string Player:: getName() const{
    return this->name;
}

int Player:: getLevel() const{
    return this->level;
}

int Player::getForce() const{
    return this->force;
}

int Player :: getHealthPoints() const{
    return this->current_HP;
}

int Player :: getCoins() const{
    return this->coins;
}


void Player:: setCharachter(Character* character){
    this->character = character; // = should be implemented
}

void Player:: setJob(Job* job){
    this->job = job; // = should be implemented
}


