
#include "MatamStory.h"
#include "Warrior.h"
#include "Archer.h"
#include "Magician.h"
#include "Player.h"
#include "Utilities.h"
#include "string"
#include <vector>
#include <iterator>



MatamStory::MatamStory(std::istream& eventsStream, std::istream& playersStream) {
    readEvents(eventsStream);
    readPlayers(playersStream);
    this->m_turnIndex = 1;
}


void MatamStory::playTurn(Player& player) {
    unique_ptr<Event>& event = events[m_turnIndex];
    printTurnDetails(m_turnIndex, player,*event);
    event->applyEvent(player);
    std::string outcome = event->getDescription();
    checkIfDead(player);




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

    /*===== TODO: Play a turn for each player =====*/

    /*=============================================*/

    printRoundEnd();

    printLeaderBoardMessage();

    /*===== TODO: Print leaderboard entry for each player using "printLeaderBoardEntry" =====*/

    /*=======================================================================================*/

    printBarrier();
}

bool MatamStory::isGameOver() const {
    /*===== TODO: Implement the game over condition =====*/
    return false; // Replace this line
    /*===================================================*/
}

void MatamStory::play() {
    printStartMessage();
    /*===== TODO: Print start message entry for each player using "printStartPlayerEntry" =====*/

    /*=========================================================================================*/
    printBarrier();

    while (!isGameOver()) {
        playRound();
    }

    printGameOver();
    /*===== TODO: Print either a "winner" message or "no winner" message =====*/

    /*========================================================================*/
}


void MatamStory::createPlayer(unique_ptr<Character> character, const string& name, string& job) {
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
                vector<unique_ptr<Monster>> members(numMembers);
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
        int count = 0;
        while (playersStream >> name >> job >> character) {
            if (character == "Responsible") {
                unique_ptr<Character> player_character = std::make_unique<Responsible>();
                createPlayer(std::move(player_character), name, job);
            } else if (character == "RiskTaking") {
                unique_ptr<Character> player_character = std::make_unique<Responsible>();
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

void MatamStory :: checkIfDead(Player& player){
    if(!(player.getCurrentHP())){
        auto it = players.begin();
        if((*it)->getName() == player.getName()){
            players.erase(players.begin());
        }
        ++it;
    }
}

bool MatamStory :: checkIfStop(Player& player){
    if(player.getLevel() == 10 || players.empty()){
        return true;
    }
    return false;

}


