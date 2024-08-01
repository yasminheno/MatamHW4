#pragma once
#include <vector>
#include <memory>
#include <string>
using std::vector;
using std::shared_ptr;
using std::unique_ptr;
using std::string;


class Monster{
protected:
    const string name;
    int combatPower;
    int loot;
    int damage;
public:
    Monster(const string& name, int combatPower ,int loot ,int damage);
    virtual const string getName() const;
    virtual int getCombatPower() const;
    virtual int getLoot() const;
    virtual int getDamage() const;

    virtual void setCombatPower(int combat_power);
    virtual void setLoot(int loot);
    virtual void setDamage(int damage);

    virtual ~Monster();

};

class Snail: public Monster{
public:
    Snail();
    ~Snail();

     const string getName() const override;
     int getCombatPower() const override;
     int getLoot() const override;
     int getDamage() const override;


};

class Slime : public Monster{
    Slime();
    ~Slime();

    const string getName() const override;
    int getCombatPower() const override;
    int getLoot() const override;
    int getDamage() const override;
};

class Balrog : public Monster{
    Balrog();
    ~Balrog();

    const string getName() const override;
    int getCombatPower() const override;
    int getLoot() const override;
    int getDamage() const override;
};


class Pack : public Monster{
private:
    vector<unique_ptr<Monster>> members;

public:
    Pack();
    ~Pack() override;
    void addMember(const Monster& monster);
    size_t getSize();

    const string getName() const override;
    int getCombatPower() const override;
    int getLoot() const override;
    int getDamage() const override;

    void setCombatPower(int combat_power) override;
    void setLoot(int loot) override;
    void setDamage(int damage) override;

};


