#include "Archer.h"
#include "Player.h"
#include "string"
using std::string;

Archer::Archer(const string &name) : Player(name,INITIAL_LEVEL,INITIAL_FORCE,
                                            INITIAL_MAXHP,INITIAL_MAXHP,
                                            ARCHER_INITIAL_COINS) {};

Archer::Archer(const string &name,const int& level,const int& force,const int& current_HP,const
int& max_HP,const int& coins) :
        Player(name,level,force,current_HP,max_HP,coins){};

Player *Archer::clone() const {
    return new Archer(*this);
}

