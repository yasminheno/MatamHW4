#include "Player.h"
#include <memory>
#pragma once


const int WARRIOR_INITIAL_MAXHP = 150;

class Warrior : public Job{


public:
     Warrior() = default;
    string getDescription(Player& player) const override;
    void Initialize(Player& player)const override;
    int getCombatPower(Player& player)const override;
    /*Warrior(const string& name,const int& level,const int& force,
            const int& current_HP,const int& max_HP,const int& coins, unique_ptr<Character> character);*/

    Warrior(const Warrior &warrior) = default;
    Warrior &operator=(const Warrior &warrior) = default;
    ~Warrior() override = default;

    std::unique_ptr<Job> clone() const override;
     string getJob() const override;


   ///int getCombatPower() override;
    void Weaken(const int &hp, Player &player) const override;
   std::unique_ptr<Player> clonePlayer(const Player& player) const override;

};

