#include "Player.h"
#include "string"
using std::string;
#pragma once

const int ARCHER_INITIAL_COINS = 20;

class Archer : public Player{

public:
    string getDescription() const override;
    explicit Archer(const string &name, unique_ptr<Character> character);
    Archer(const string& name,const int& level,const int& force,
           const int& current_HP,const int& max_HP,const int& coins, unique_ptr<Character> character);

    Archer(const Archer &archer) = default;
    Archer &operator=(const Archer &archer) = default;
    ~Archer() override = default;
    std::unique_ptr<Player> clone() const override;
    string getJob() const override;
    void Weaken(const int& hp) override;

    //int getCombatPower() override;
};

