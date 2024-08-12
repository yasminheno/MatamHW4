#include "Monster.h"

#include "Utilities.h"
#include "string"
#include <utility>
#include <vector>

Monster :: Monster(const string& name, int combatPower ,int loot ,int damage) :
name(name), combatPower(combatPower), loot(loot), damage(damage){}

string Monster:: getName() const {
    return this->name;
}

int Monster :: getLoot() const {
    return this->loot;
}

int Monster ::getCombatPower() const {
    return this->combatPower;
}

int Monster ::getDamage() const {
    return this->damage;
}

void Monster::setCombatPower(int combat_power) {
    this->combatPower = combat_power;
}

void Monster::setLoot(int loot) {
     this->loot = loot;
}

void Monster::setDamage(int damage) {
    this->damage = damage;
}



Monster::Monster(const string &name) : name(name) {};

Snail :: Snail() : Monster("Snail",
                           INITAL_SNAIL_COMBATPOWER,
                           INITAL_SNAIL_LOOT, INITAL_SNAIL_DAMAGE){}

void Snail::setCombatPower(int combat_power) {
    Monster::setCombatPower(combat_power);
}

void Snail::setLoot(int loot) {
    Monster::setLoot(loot);
}

void Snail::setDamage(int damage) {
    Monster::setDamage(damage);
}

int Snail::getCombatPower() const {
    return Monster::getCombatPower();
}

int Snail::getLoot()const {
    return Monster::getLoot();
}

int Snail::getDamage() const {
    return Monster::getDamage();
}



Balrog ::Balrog() : Monster("Balrog", INITAL_BALROG_COMBATPOWER,
                            INITAL_BALROG_LOOT, INITAL_BALROG_DAMAGE){}

void Balrog::setCombatPower(int combat_power) {
    Monster::setCombatPower(combat_power);
}

void Balrog::setLoot(int loot) {
    Monster::setLoot(loot);
}

void Balrog::setDamage(int damage) {
    Monster::setDamage(damage);
}

int Balrog::getCombatPower() const {
    return Monster::getCombatPower();
}

int Balrog::getLoot()const {
    return Monster::getLoot();
}

int Balrog::getDamage() const {
    return Monster::getDamage();
}



Slime ::Slime() : Monster("Slime", INITAL_SLIME_COMBATPOWER,
                          INITAL_SLIME_LOOT, INITAL_SILME_DAMAGE){}

void Slime::setCombatPower(int combat_power) {
    Monster::setCombatPower(combat_power);
}

void Slime::setLoot(int loot) {
    Monster::setLoot(loot);
}

void Slime::setDamage(int damage) {
    Monster::setDamage(damage);
}

int Slime::getCombatPower() const {
    return Monster::getCombatPower();
}

int Slime::getLoot()const {
    return Monster::getLoot();
}

int Slime::getDamage() const {
    return Monster::getDamage();
}



Pack ::Pack(vector<unique_ptr<Monster>> members)
    : Monster("Pack", 0, 0, 0), members(std::move(members)){
        for (const auto& member : this->members) {
            this->combatPower += member->getCombatPower();
            this->damage += member->getDamage();
            this->loot += member->getLoot();
        }
}



void Pack::setCombatPower(int combat_power) {
    Monster::setCombatPower(combat_power);
}

void Pack::setLoot(int loot) {
    Monster::setLoot(loot);
}

void Pack::setDamage(int damage) {
    Monster::setDamage(damage);
}

int Pack::getCombatPower() const {
    return Monster::getCombatPower();
}

int Pack::getDamage() const {
    return Monster::getDamage();
}

int Pack::getLoot() const {
    return Monster::getLoot();
}

size_t Pack::getSize() const {
    return this->members.size();
}

void Pack::addMember(unique_ptr<Monster> monster) {
        this->combatPower += monster->getCombatPower();
        this->damage += monster->getDamage();
        this->loot += monster->getLoot();
        this->members.push_back(std::move(monster));
}





