#pragma once
#include <vector>
using std::vector;


class Monster{
public:
    Monster(const int combatPower,const int loot, int damage);

};

class Snail: Monster{
public:
    Snail(const int combatPower = 5,const int loot = 2, const int damage = 10);
};

class Slime : Monster{
    Slime(const int combatPower = 12,const int loot = 5, const int damage = 25);
};

class Balrog : Monster{
    Balrog(const int combatPower = 15,const int loot = 100, int damage = 9001);
};
class Pack : Monster{
public:
    int num_of_monsters;
    vector<Monster> pack_monster;
    Pack(int combatPower, int loot, int damage);
};
