#pragma once
#include <vector>
#include <memory>
#include <string>
using std::vector;
using std::shared_ptr;
using std::unique_ptr;
using std::string;


class Monster{
    friend class Pack;//why do we need this if pack inherits from monster?
protected:
    const string name;
    int combatPower;
    int loot;
    int damage;
    virtual string getName() const;
    virtual int getCombatPower() const;

    virtual int getDamage() const;

    virtual int getLoot() const;

public:
    Monster(const string& name, int combatPower ,int loot ,int damage);
    virtual void setCombatPower(int combat_power);
    virtual void setLoot(int loot);
    virtual void setDamage(int damage);

    virtual ~Monster() = default;

};

class Snail: public Monster{
public:
    Snail();
    ~Snail();
    void setCombatPower(int combat_power) override;
    void setLoot(int loot) override;
    void setDamage(int damage) override;
    int getCombatPower() const override;
    int getDamage() const override;
    int getLoot() const override;


};

class Slime : public Monster{
    Slime();
    ~Slime();
    void setCombatPower(int combat_power) override;
    void setLoot(int loot) override;
    void setDamage(int damage) override;
    int getCombatPower() const override;
    int getDamage() const override;
    int getLoot() const override;

};

class Balrog : public Monster{
    Balrog();
    ~Balrog();
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
    ~Pack() override;
    void addMember(const unique_ptr<Monster> monster);
    size_t getSize();


    void setCombatPower(int combat_power) override;
    void setLoot(int loot) override;
    void setDamage(int damage) override;
    int getCombatPower() const override;
    int getDamage() const override;
    int getLoot() const override;

};





