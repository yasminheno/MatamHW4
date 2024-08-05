#include "Player.h"
#include "string"
using std::string;

const int ARCHER_INITIAL_COINS = 20;

class Archer : public Player{

public:
    string getDescription() const override;
    explicit Archer(const string &name);
    Archer(const string& name,const int& level,const int& force,
           const int& current_HP,const int& max_HP,const int& coins);

    Archer(const Archer &warrior) = default;
    Archer &operator=(const Archer &warrior) = default;
    ~Archer() override = default;
    Player* clone() const override;
};


