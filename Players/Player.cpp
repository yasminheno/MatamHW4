#include "Player.h"
#include "Utilities.h"
#include "string"
#include <utility>
#include <vector>
using std::unique_ptr;

Player::Player(const string &name, unique_ptr<Character> character,unique_ptr<Job> job) : name(name), level(INITIAL_LEVEL), force(INITIAL_FORCE)
        ,current_HP(INITIAL_MAXHP),max_HP(INITIAL_MAXHP),coins(INITIAL_COINS), character(std::move(character)),
                                                                                         job(std::move(job)){
};


Player::Player(const string &name,const int &level,const int &force,const int &current_HP,
               const int &max_HP,const int &coins, unique_ptr<Character> character, unique_ptr<Job> job):
        name(name), level(level), force(force), current_HP(current_HP), max_HP(max_HP), coins(coins),
        character(std::move(character)), job(std::move(job)){};


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
coins(other.coins), character(other.character ? other.character->clone() : nullptr),
                                      job(other.job ? other.job->clone() : nullptr){};

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
        if (other.job) {
           job = unique_ptr<Job>(other.job->clone());
        } else {
            job = nullptr;
        }
    }
    return *this;
}



void Player::setForce(const int& force) {
    this->force = force;
}

string Player::getCharacter() const {
    return this->character->getDescription();
}



int Player::getCurrentHP() const {
    return this->current_HP;
}

int Player::getMaxHP() const {
    return this->max_HP;
}

bool Player::canPlayerPay(int coins) const {
    if(this->coins - coins < 0)
    {
        return false;
    }

    return true;
}

bool Player::check_adding_HP(int hp) const {
    if(this->current_HP + hp > this->max_HP) {
        return false;
    }
    return true;
}

void Player::levelUp() {
    if(this->level + 1 <= 10)
    {
        this->level++;
    }
}

void Player::addCoins(int coins) {
   this->coins += coins;
}

void Player::decreaseCoins(int coins) {
    if(canPlayerPay(coins))
    {
        this->coins -= coins;
    }
}

void Player::addCurrentHP(const int &hp) {
   if(check_adding_HP(hp))
   {
       this->current_HP += hp;
   } else {
       this->current_HP = max_HP;
   }
}

void Player::checkOutCome(const std::string &outcome) {
    this->outcome = outcome;
}

string Player::getOutCome() {
    return outcome;
}

void Player::decreaseCurrentHP(const int &damage) {
    if(current_HP - damage >= 0)
    {
        current_HP -= damage;
    } else{
        current_HP = 0;
    }
}

int Player::getCombatPower() {
    return this->force + this->level;
}

string Player::getJobType() const {
    return this->job->getJob();
}

void Player::setMaxHP(const int &hp) {
    this->max_HP = hp;
}

void Player::setCurrentHP(const int &hp) {
    this->current_HP = hp;
}

unique_ptr<Character> Player::getCharacter_ptr() const {
    return std::unique_ptr<Character>(character->clone());
}

std::unique_ptr<Player> Player::clone() const {
    return job->clonePlayer(*this);
}

string Player::getDescription() const {
    string desc = name + ", " + job->getJob() + " with " + character->getDescription()
       + " character (level " + std::to_string(level) + ", force " + std::to_string(force) + ")";
    return desc;
}

void Player::setCoins(const int &coins) {
    this->coins = coins;
}

unique_ptr<Job> Player::getJob_ptr() const {
    return std::unique_ptr<Job>(job->clone());
}