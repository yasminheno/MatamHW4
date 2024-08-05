#include "Player.h"
#include "string"

class Magician : public Player{
public:
public:
    explicit Magician(const string &name);
    Magician(const string& name,const int& level,const int& force,
             const int& current_HP,const int& max_HP,const int& coins);

    Magician(const Magician &magician) = default;
    Magician &operator=(const Magician &magician) = default;
    ~Magician() override = default;
    Player* clone() const override;
};
