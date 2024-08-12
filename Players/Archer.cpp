#include <sstream>
#include "Player.h"
#include "Archer.h"
#include "string"
#include <vector>
#include <memory>
using std::string;

void Archer::Initialize(Player &player) const {
    player.setCoins(ARCHER_INITIAL_COINS);
}

int Archer::getCombatPower(Player& player) const {
    return player.getForce() + player.getLevel();  // Adjust this formula if necessary for archers
}

std::unique_ptr<Job> Archer::clone() const {
    return std::make_unique<Archer>(*this);
}

string Archer::getDescription(Player& player) const {
    std::ostringstream os;
    os << player.getName() << ", " << "Archer" << " with " << player.getCharacter()
       << " character (level " << player.getLevel() << ", force " << player.getForce() << ")";
    return os.str();
}

string Archer::getJob() const {
    return "Archer";
}

void Archer::Weaken(const int &hp, Player& player) const {
    return;
}

std::unique_ptr<Player> Archer::clonePlayer(const Player &player) const {
    return std::make_unique<Player>(
            player.getName(), player.getLevel(), player.getForce(),
            player.getCurrentHP(), player.getMaxHP(), player.getCoins(),
            player.getCharacter_ptr(),  // Clone the character
            this->clone()  // Clone the Job (Archer in this case)
    );
}
