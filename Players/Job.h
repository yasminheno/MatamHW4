#pragma once
#include "Player.h"
#include <memory>

class Player;

class Job{
private:
    friend class Player;
public:
    virtual ~Job() = default;
    virtual string getDescription(Player& player) const = 0;
    virtual string getJob() const =0;
    virtual void Weaken(const int& hp ,Player& player) const = 0;
    virtual std::unique_ptr<Job> clone() const = 0;
    virtual void Initialize(Player& player) const = 0;
    virtual int getCombatPower(Player& player) const = 0;
    virtual std::unique_ptr<Player> clonePlayer(const Player& player) const = 0;

};
