#include "Player.h"
#include "string"
#pragma once

class Magician : public Player{
public:
    string getDescription() const override;
    explicit Magician(const string &name, unique_ptr<Character> character);
    Magician(const string& name,const int& level,const int& force,
             const int& current_HP,const int& max_HP,const int& coins, unique_ptr<Character> character);

    Magician(const Magician &magician) = default;
    Magician &operator=(const Magician &magician) = default;
    ~Magician() override = default;
    Player* clone() const override;
    string getJob() const override;
    void setForce(const int& force) override;
    void Weaken(const int& hp) override;

    //int getCombatPower() override;
};