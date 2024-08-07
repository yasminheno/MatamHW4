
#include "MatamStory.h"
#include "Players/Warrior.h"
#include "Players/Archer.h"
#include "Players/Magician.h"
#include "Players/Player.h"
#include "Utilities.h"
#include "string"
#include <vector>
#include <iterator>



MatamStory::MatamStory(std::istream& eventsStream, std::istream& playersStream) {
    readEvents(eventsStream);
    readPlayers(playersStream);
    this->m_turnIndex = 0;
}


void MatamStory::playTurn(Player& player) {
    unique_ptr<Event>& event = events[m_turnIndex % events.size()];
    printTurnDetails(m_turnIndex + 1, player,*event);
    event->applyEvent(player);
    checkIfDead(player);
    printTurnOutcome(player.getOutCome());
    /**
     * Steps to implement (there may be more, depending on your design):
     * 1. Get the next event from the events list
     * 2. Print the turn details with "printTurnDetails"
     * 3. Play the event
     * 4. Print the turn outcome with "printTurnOutcome"
    */

    m_turnIndex++;
}

void MatamStory::playRound(){

    printRoundStart();
    for (size_t i = 0; i < players.size(); ++i) {
        playTurn(*players[i]);
    }
    printRoundEnd();
    printLeaderBoardMessage();
    for (size_t i = 0; i < players.size(); ++i) {
        printLeaderBoardEntry(i,*players[i]);
    }
    printBarrier();
}

bool MatamStory::isGameOver() const {
    for (size_t i = 0; i < players.size(); ++i) {
        if(checkIfStop(*players[i]))
        {
            return true;
        }
    }
    return false;
}

void MatamStory::play() {
    printStartMessage();
    printLeaderBoardMessage();
    for (size_t i = 1; i <= players.size(); ++i) {
        printStartPlayerEntry(i,*players[i]);
    }
    printBarrier();
    while(!isGameOver()) {
        playRound();
    }
    printGameOver();
    Player* winner = nullptr;
    for (size_t i = 0; i < players.size(); ++i) {
        Player* player = players[i].get();
        if (winner == nullptr || player->getLevel() > winner->getLevel()) {
            winner = player;
        } else if (player->getLevel() == winner->getLevel()) {
            if (player->getCoins() > winner->getCoins() ||
                (player->getCoins() == winner->getCoins() && player->getName() < winner->getName())) {
                winner = player;
            }
        }
    }

    if (winner && winner->getLevel() == 10) {
        printWinner(*winner);
    } else {
       printNoWinners();
    }
}


void MatamStory::createPlayer(unique_ptr<Character> character, const string& name,const string& job) {
    if (job == "Warrior") {
       players.push_back(std::make_unique<Warrior>(name, std::move(character)));
    } else if (job == "Magician") {
        players.push_back(std::make_unique<Magician>(name, std::move(character)));
    } else if (job == "Archer") {
        players.push_back(std::make_unique<Archer>(name, std::move(character)));
    } else {
        throw std::runtime_error("Invalid job type");
    }
}

void MatamStory :: readEvents(std::istream& eventsStream) {
    try {
        string eventType, monster;
        while (eventsStream >> eventType) {
            if (eventType == "Snail") {
                events.push_back(std::make_unique<Encounter>(std::make_unique<Snail>()));
            } else if (eventType == "Balrog") {
                events.push_back(std::make_unique<Encounter>(std::make_unique<Balrog>()));
            } else if (eventType == "Slime") {
                events.push_back(std::make_unique<Encounter>(std::make_unique<Slime>()));
            } else if (eventType == "SolarEclipse") {
                events.push_back(std::make_unique<SolarEclipse>());
            } else if (eventType == "PotionsMerchant") {
                events.push_back(std::make_unique<PotionsMerchant>());
            } else if (eventType == "Pack") {
                int numMembers;
                eventsStream >> numMembers;
                vector<unique_ptr<Monster>> members/*(numMembers)*/;
                Pack pack(std::move(members));
                for (int i = 0; i < numMembers; ++i) {
                    eventsStream >> monster;
                    members.push_back(std::make_unique<Monster>(monster));
                }
                events.push_back(std::make_unique<Encounter>(std::make_unique<Pack>(std::move(members))));
            } else {
                throw std::runtime_error("Invalid event type");
            }
        }

    } catch (const std::exception &e) {
        std::cerr << e.what() << std::endl;
    }
}

void MatamStory :: readPlayers(std::istream& playersStream){
    try {
        string name, word, character, job;
        while (playersStream >> name >> job >> character) {
            if (character == "Responsible") {
                unique_ptr<Character> player_character = std::make_unique<Responsible>();
                createPlayer(std::move(player_character), name, job);
            } else if (character == "RiskTaking") {
                unique_ptr<Character> player_character = std::make_unique<RiskTaking>();
                createPlayer(std::move(player_character), name, job);
            } else {
                throw std::runtime_error("Invalid character type");
            }
            if (name.length() < 3 || name.length() > 15) {
                std::cerr << "Invalid Players File" << std::endl;
                return;
            }
        }
        if (players.size() < 2 || players.size() > 6 ) {
            std::cerr << "Invalid Players File" << std::endl;
            return;
        }

    } catch (const std::exception &e) {
        std::cerr << e.what() << std::endl;

    }
}

void MatamStory :: checkIfDead(Player& player) {
    m_turnIndex = 0;
    for (size_t i = 0; i < players.size(); i++) {
        if (!(player.getCurrentHP())) {
            players.erase(players.begin() + m_turnIndex);
        }
        m_turnIndex++;
    }
}
    /*if(!(player.getCurrentHP())){
        auto it = players.begin();
        for(; it != players.end(); ++it){
            if ((*it)->getName() == player.getName()) {
                it = players.erase(it); // Remove the player and update the iterator
            } else {
                ++it; // Move to the next player
            }
        }
    }
}*/
bool MatamStory::checkIfStop(Player &player) const {
    return (player.getLevel() == 10 || players.empty());
}

