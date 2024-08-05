#include <sstream>
#include "Archer.h"
#include "Player.h"
#include "string"
using std::string;

Archer::Archer(const string &name, unique_ptr<Character> character) : Player(name,INITIAL_LEVEL,INITIAL_FORCE,
                                            INITIAL_MAXHP,INITIAL_MAXHP,
                                            ARCHER_INITIAL_COINS, std::move(character)) {};

Archer::Archer(const string &name,const int& level,const int& force,const int& current_HP,const
int& max_HP,const int& coins, unique_ptr<Character> character) :
        Player(name,level,force,current_HP,max_HP,coins, std::move(character)){};

Player *Archer::clone() const {
    return new Archer(*this);
}
string Archer::getDescription() const {
    std::ostringstream os;
    os << name << ", " << "Warrior" << " with " << character->getDescription()
       << " character (level " << level << ", force " << force << ")";
    return os.str();
}

