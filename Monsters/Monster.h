#pragma once
#include <vector>
#include <memory>
#include <string>
using std::vector;
using std::shared_ptr;
using std::unique_ptr;
using std::string;

const int INITAL_SNAIL_COMBATPOWER = 5;
const int INITAL_SNAIL_LOOT = 2;
const int INITAL_SNAIL_DAMAGE = 10;

const int INITAL_BALROG_COMBATPOWER = 15;
const int INITAL_BALROG_LOOT = 100;
const int INITAL_BALROG_DAMAGE = 9001;

const int INITAL_SLIME_COMBATPOWER = 12;
const int INITAL_SLIME_LOOT = 5;
const int INITAL_SILME_DAMAGE = 25;

class Monster{
protected:
    const string name;
    int combatPower;
    int loot;
    int damage;


public:
    Monster(const string& name, int combatPower ,int loot ,int damage);
    virtual void setCombatPower(int combat_power);
    virtual void setLoot(int loot);
    virtual void setDamage(int damage);
    virtual string getName() const;
    virtual int getCombatPower() const;
    virtual int getDamage() const;
    virtual int getLoot() const;
    virtual ~Monster() = default;

};

class Snail: public Monster{
public:
    Snail();
    void setCombatPower(int combat_power) override;
    void setLoot(int loot) override;
    void setDamage(int damage) override;
    int getCombatPower() const override;
    int getDamage() const override;
    int getLoot() const override;


};

class Slime : public Monster{
    Slime();
    void setCombatPower(int combat_power) override;
    void setLoot(int loot) override;
    void setDamage(int damage) override;
    int getCombatPower() const override;
    int getDamage() const override;
    int getLoot() const override;

};

class Balrog : public Monster{
    Balrog();
    void setCombatPower(int combat_power) override;
    void setLoot(int loot) override;
    void setDamage(int damage) override;
    int getCombatPower() const override;
    int getDamage() const override;
    int getLoot() const override;

};


class Pack : public Monster{
private:
    vector<unique_ptr<Monster>> members;


public:
    Pack(vector<unique_ptr<Monster>> members);
    void addMember(unique_ptr<Monster> monster);
    size_t getSize();
    void setCombatPower(int combat_power) override;
    void setLoot(int loot) override;
    void setDamage(int damage) override;
    int getCombatPower() const override;
    int getDamage() const override;
    int getLoot() const override;

};





