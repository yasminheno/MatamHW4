
#include "MatamStory.h"
#include "Warrior.h"
#include "Archer.h"
#include "Magician.h"
#include "Player.h"
#include "Utilities.h"
#include "string"
#include <vector>



MatamStory::MatamStory(std::istream& eventsStream, std::istream& playersStream) {
    try {
        string line, name, word, character, job;
        int count = 0;
        while (playersStream >> name >> job >> character) {
            if (character == "Responsible") {
                unique_ptr<Character> player_character = std::make_unique<Responsible>();
                createplayer(std::move(player_character), name, job);
            } else if (character == "RiskTaking") {
                unique_ptr<Character> player_character = std::make_unique<Responsible>();
                createplayer(std::move(player_character), name, job);
            } else {
                throw std::runtime_error("Invalid character type");
            }
            if (name.length() < 3 || name.length() > 15) {
                std::cerr << "Invalid Players File" << std::endl;
                return;
            }
        }
        if (players.size() < 2) {
            std::cerr << "Invalid Players File" << std::endl;
            return;
        }

    } catch (const std::exception& e) {
        std::cerr << e.what() << std::endl;
    /*===== TODO: Open and read events file =====*/
    /*===== TODO: Open and Read players file =====*/


    this->m_turnIndex = 1;
}

void MatamStory::playTurn(Player& player) {

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
}

void MatamStory::createplayer(unique_ptr<Character> character, const string& name, string& job) {
    std::vector<std::unique_ptr<Player>> game_players;
    if (job == "Warrior") {
        game_players.push_back(std::make_unique<Warrior>(name, std::move(character)));
    } else if (job == "Magician") {
        game_players.push_back(std::make_unique<Magician>(name, std::move(character)));
    } else if (job == "Archer") {
        game_players.push_back(std::make_unique<Archer>(name, std::move(character)));
    } else {
        throw std::runtime_error("Invalid job type");
    }
}

}
