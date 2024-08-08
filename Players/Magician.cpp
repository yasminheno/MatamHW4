#include <sstream>
#include "Magician.h"

Magician::Magician(const std::string &name, unique_ptr<Character> character) : Player(name, std::move(character)){};


Magician::Magician(const std::string &name, const int &level, const int &force,
                   const int &current_HP, const int &max_HP, const int &coins,
                   unique_ptr<Character> character) :
        Player(name,level,force,coins,max_HP,coins, std::move(character)) {};

Player *Magician::clone() const {
    return new Magician(*this);
}

string Magician::getDescription() const {
    std::ostringstream os;
    os << name << ", " << "Magician" << " with " << character->getDescription()
       << " character (level " << level << ", force " << force << ")";
    return os.str();
}

string Magician::getJob() const {
    return "Magician";
}

void Magician::setForce(const int &force) {
    this->force++;
}

void Magician::Weaken(const int &hp) {
    return;
}