#include <sstream>
#include "Magician.h"

Magician::Magician(const std::string &name) : Player(name){};


Magician::Magician(const std::string &name, const int &level, const int &force,
                   const int &current_HP, const int &max_HP, const int &coins) :
        Player(name,level,force,coins,max_HP,coins) {};

Player *Magician::clone() const {
    return new Magician(*this);
}

string Magician::getDescription() const {
    std::ostringstream os;
    os << name << ", " << "Warrior" << " with " << character->getDescription()
       << " character (level " << level << ", force " << force << ")";
    return os.str();
}

