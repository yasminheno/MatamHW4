#include <sstream>
#include "Player.h"
#include "Magician.h"
#include "string"
#include <vector>
#include <memory>
using std::string;

void Magician::Initialize(Player &player) const {
    return;
}

int Magician::getCombatPower(Player& player) const {
    return player.getForce() + player.getLevel();;  // Adjust this formula if necessary for magicians
}

std::unique_ptr<Job> Magician::clone() const {
    return std::make_unique<Magician>(*this);
}

string Magician::getDescription(Player& player) const {
    std::ostringstream os;
    os << player.getName() << ", " << "Magician" << " with " << player.getCharacter()
       << " character (level " << player.getLevel() << ", force " << player.getForce() << ")";
    return os.str();
}

string Magician::getJob() const {
    return "Magician";
}

void Magician::Weaken(const int &hp, Player& player) const {
    return;
}

std::unique_ptr<Player> Magician::clonePlayer(const Player &player) const {
    return std::make_unique<Player>(
            player.getName(), player.getLevel(), player.getForce(),
            player.getCurrentHP(), player.getMaxHP(), player.getCoins(),
            player.getCharacter_ptr(),  // Clone the character
            this->clone()  // Clone the Job (Magician in this case)
    );
}
