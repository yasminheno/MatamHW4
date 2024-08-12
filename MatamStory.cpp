
#include "MatamStory.h"
#include "Players/Warrior.h"
#include "Players/Archer.h"
#include "Players/Magician.h"
#include "Players/Player.h"
#include "Utilities.h"
#include "string"
#include <vector>
#include <iterator>
#include <algorithm>


MatamStory::MatamStory(std::istream& eventsStream, std::istream& playersStream) {
    readEvents(eventsStream);
    readPlayers(playersStream);
    this->m_turnIndex = 0;
}


void MatamStory::playTurn(Player& player) {
    unique_ptr<Event>& event = events[m_turnIndex % events.size()];
    printTurnDetails(m_turnIndex + 1, player,*event);
    event->applyEvent(player);
    printTurnOutcome(player.getOutCome());
    m_turnIndex++;
}

bool playerComparator(const std::unique_ptr<Player>& a, const std::unique_ptr<Player>& b) {
    if (a->getLevel() != b->getLevel()) {
        return a->getLevel() > b->getLevel();
    }
    if (a->getCoins() != b->getCoins()) {
        return a->getCoins() > b->getCoins();
    }
    return a->getName() < b->getName();
}

void PrintSortedBoard(const std::vector<std::unique_ptr<Player>>& players) {
    printLeaderBoardMessage();
    std::vector<std::unique_ptr<Player>> sortedPlayers;

    // Clone players for sorting
    sortedPlayers.reserve(players.size());
for (const auto& player : players) {
        sortedPlayers.push_back(player->clone());
    }

    std::sort(sortedPlayers.begin(), sortedPlayers.end(), playerComparator);

    for (size_t i = 0; i < sortedPlayers.size(); ++i) {
        printLeaderBoardEntry(i + 1, *sortedPlayers[i]);
    }
    printBarrier();
}


void MatamStory::playRound(){

    printRoundStart();
    for (size_t i = 0; i < players.size();++i) {
        if(players[i]->getCurrentHP() != 0)
        {
            playTurn(*players[i]);
        }
    }
    printRoundEnd();
    PrintSortedBoard(players);
}

bool MatamStory::isGameOver() const {

    size_t count = 0;
    for (size_t i = 0; i < players.size(); ++i) {
        if (players[i]->getLevel() == 10) {
            return true;
        }
        if(players[i]->getCurrentHP() == 0)
        {
            count++;
        }
    }
    if(count == players.size())
    {
        return true;
    }

    return false;
}


void MatamStory::play() {
    printStartMessage();
    for (size_t i = 0; i < players.size(); ++i) {
        printStartPlayerEntry(i + 1,*players[i]);
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
            if (player->getCoins() > winner->getCoins()){
                winner = player;
            } else if((player->getName() < winner->getName())){
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

//fix thiese  players.push_back(std::make_unique<Player>(
void MatamStory::createPlayer(unique_ptr<Character> character, const string& name,const string& job) {

        std::unique_ptr<Player> player;
        if (job == "Warrior") {
            player = std::make_unique<Player>(name, std::move(character), std::make_unique<Warrior>());
        } else if (job == "Magician") {
            player = std::make_unique<Player>(name, std::move(character), std::make_unique<Magician>());
        } else if (job == "Archer") {
            player = std::make_unique<Player>(name, std::move(character), std::make_unique<Archer>());
        } else {
            throw std::runtime_error("Invalid job type");
        }

        player->getJob_ptr()->Initialize(*player);
        players.push_back(std::move(player));
}

    void MatamStory :: readEvents(std::istream& eventsStream) {
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
                    add_Pack(eventsStream);
                } else {
                    throw std::runtime_error("Invalid Events File");
                }
            }
    }



void MatamStory :: readPlayers(std::istream& playersStream){
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
                throw std::runtime_error("Invalid Players File");
            }
        }
        if (players.size() < 2 || players.size() > 6 ) {
            throw std::runtime_error("Invalid Players File");
        }
}




void MatamStory::add_Pack(std::istream& eventsStream) {
        int numMembers;
        std::string monsterType;
        if (!(eventsStream >> numMembers) || numMembers < 2) {
            throw std::runtime_error("Invalid Events File");
        }
        std::vector<std::unique_ptr<Monster>> members;
        for (int i = 0; i < numMembers; ++i) {
            if (!(eventsStream >> monsterType)) {
                throw std::runtime_error("Invalid Events File");
            }
            if (monsterType == "Snail") {
                members.push_back(std::make_unique<Snail>());
            } else if (monsterType == "Balrog") {
                members.push_back(std::make_unique<Balrog>());
            } else if (monsterType == "Slime") {
                members.push_back(std::make_unique<Slime>());
            } else if (monsterType == "Pack") {
                std::vector<std::unique_ptr<Monster>> subPackMembers;
                add_Pack(eventsStream);
                members.push_back(std::make_unique<Pack>(std::move(subPackMembers)));
            } else {
                throw std::runtime_error("Invalid monster type");
            }
        }
        events.push_back(std::make_unique<Encounter>(std::make_unique<Pack>(std::move(members))));
}