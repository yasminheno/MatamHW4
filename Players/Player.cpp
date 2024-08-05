#include "Player.h"

#include "Utilities.h"
#include "Charachter.h"
#include "Job.h"
#include "string"
#include <utility>
#include <vector>

Player :: Player(const string& name, int level, int force, int current_HP, int max_HP, int coins,
       Character* character, Job* job)
        : name(name), level(level), force(force), current_HP(current_HP), max_HP(max_HP), coins(coins),
          character(character), job(job) {}//character(std::move(character))

string Player:: getDescription() const{
    string os = this->getName() << ", " << this->job->getDescription() << "with"
            << this->character->getDescription() << "character (level" <<
            this->level << " ,force" << this->force << ")";
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


