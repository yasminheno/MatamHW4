#pragma once
#include "Player.h"
#include "string"
#include <memory>


class Magician : public Job {
public:
    Magician() = default;
    string getDescription(Player& player) const override;
    void Initialize(Player& player) const override;
    int getCombatPower(Player& player) const override;

    Magician(const Magician &magician) = default;
    Magician &operator=(const Magician &magician) = default;
    ~Magician() override = default;

    std::unique_ptr<Job> clone() const override;
    string getJob() const override;

    void Weaken(const int &hp, Player& player) const override;
    std::unique_ptr<Player> clonePlayer(const Player& player) const override;
};