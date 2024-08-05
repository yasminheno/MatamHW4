#include "Player.h"


const int WARRIOR_INITIAL_MAXHP = 150;

class Warrior : public Player{


public:
    Warrior();
    string getDescription() const override;
    explicit Warrior(const string &name, unique_ptr<Character> character);
    Warrior(const string& name,const int& level,const int& force,
            const int& current_HP,const int& max_HP,const int& coins, unique_ptr<Character> character);

    Warrior(const Warrior &warrior) = default;
    Warrior &operator=(const Warrior &warrior) = default;
    ~Warrior() override = default;
    Player* clone() const override;
};
