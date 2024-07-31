
#include "MatamStory.h"

#include "Utilities.h"
#include "string"
#include <vector>



MatamStory::MatamStory(std::istream& eventsStream, std::istream& playersStream) {
   /* try{
        string line, name;
        Job job; int i; int count = 0; string word; Character character;
        while(getline(playersStream, line) ){
            i = 0;
            count = 0;
            while (count < 3) {
                count++;
                while (i < line.length() && line[i] != ' ') {
                    word += line[i];
                    i++;
                }
                switch (count) {
                    case 1:
                        name = word;
                        break;
                    case 2:
                        job = word;
                        break;
                    case 3:
                        Character = word;
                        break;*/
       /* string line;
        while(getline(eventsStream, line)){
            events.push_back(event(line));
        }*/
    }
    /*===== TODO: Open and read events file =====*/

    /*==========================================*/


    /*===== TODO: Open and Read players file =====*/

    /*============================================*/


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

void MatamStory::playRound() {

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
