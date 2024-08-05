#include "Player.h"
#include "Charachter.h"

#include "Utilities.h"
#include "string"
#include <utility>
#include <vector>
using std::unique_ptr;

Player::Player(const string &name) : name(name), level(INITIAL_LEVEL), force(INITIAL_FORCE)
        ,current_HP(INITIAL_MAXHP),max_HP(INITIAL_MAXHP),coins(INITIAL_COINS){}


Player::Player(const string &name,const int &level,const int &force,const int &current_HP,
               const int &max_HP,const int &coins):
        name(name), level(level), force(force), current_HP(current_HP), max_HP(max_HP), coins(coins) {}



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



Player::Player(const Player &other) : name(other.name), level(other.level), force(other.force),
current_HP(other.current_HP), max_HP(other.max_HP),
coins(other.coins), character(other.character ? other.character->clone() : nullptr){}

Player &Player::operator=(const Player &other) {
    if (this != &other) {
        level = other.level;
        force = other.force;
        current_HP = other.current_HP;
        max_HP = other.max_HP;
        coins = other.coins;

        if (other.character) {
            character = unique_ptr<Character>(other.character->clone());
        } else {
            character = nullptr;
        }
    }
    return *this;
}

int Player::getCombatPower() {
    return this->force + this->level;
}









