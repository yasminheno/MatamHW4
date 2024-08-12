#pragma once
#include "Player.h"
#include "string"
using std::string;
#include <memory>


const int ARCHER_INITIAL_COINS = 20;

class Archer : public Job {
public:
    Archer() = default;
    string getDescription(Player& player) const override;
    void Initialize(Player& player) const override;
    int getCombatPower(Player& player) const override;

    Archer(const Archer &archer) = default;
    Archer &operator=(const Archer &archer) = default;
    ~Archer() override = default;

    std::unique_ptr<Job> clone() const override;
    string getJob() const override;

    void Weaken(const int &hp, Player &player) const override;
    std::unique_ptr<Player> clonePlayer(const Player& player) const override;
};

