#include <sstream>
#include "Player.h"
#include "Warrior.h"
#include "string"
#include <vector>
using std::string;


void Warrior::Initialize(Player &player) const{
    player.setMaxHP(WARRIOR_INITIAL_MAXHP);
    player.setCurrentHP(WARRIOR_INITIAL_MAXHP);
}

int Warrior::getCombatPower(Player& player) const {
    return (player.getForce()) * 2 + player.getLevel();
}

std::unique_ptr<Job> Warrior::clone() const {
    return std::make_unique<Warrior>(*this);
}


string Warrior::getDescription(Player& player) const {
    std::ostringstream os;
    os << player.getName() << ", " << "Warrior" << " with " << player.getCharacter()
        << " character (level " << player.getLevel() << ", force " << player.getForce() << ")";
    return os.str();
}

string Warrior::getJob() const {
    return "Warrior";
}

void Warrior::Weaken(const int &hp, Player& player)const {
    if(player.getCurrentHP() - hp >= 0)
    {
        player.setCurrentHP(player.getCurrentHP()-hp);
    } else{
        player.setCurrentHP(0);
    }
}

std::unique_ptr<Player> Warrior::clonePlayer(const Player &player) const {
    return std::make_unique<Player>(
            player.getName(), player.getLevel(), player.getForce(),
            player.getCurrentHP(), player.getMaxHP(), player.getCoins(),
            player.getCharacter_ptr(),  // Clone the character
            this->clone()  // Clone the Job (Warrior in this case)
    );
}

