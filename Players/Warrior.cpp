#include <sstream>
#include "Player.h"
#include "Warrior.h"
#include "string"
using std::string;

Warrior::Warrior(const string &name) : Player(name,INITIAL_LEVEL,INITIAL_FORCE,
                                              WARRIOR_INITIAL_MAXHP
        , WARRIOR_INITIAL_MAXHP,INITIAL_COINS) {};

Warrior::Warrior(const string &name,const int& level,const int& force,const int& current_HP,const
int& max_HP,const int& coins) :
        Player(name,level,force,current_HP,max_HP,coins){};

Player *Warrior::clone() const {
    return new Warrior(*this);
}

string Warrior::getDescription() const {
    std::ostringstream os;
    os << name << ", " << "Warrior" << " with " << character->getDescription()
        << " character (level " << level << ", force " << force << ")";
    return os.str();
}
