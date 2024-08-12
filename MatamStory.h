
#pragma once

#include <iostream>
#include <vector>

#include "Players/Player.h"
#include "Events/Event.h"
#include "Events/Monster.h"

using std::vector;
class MatamStory{
private:
    vector<unique_ptr<Player>> players;
    vector<unique_ptr<Event>> events;
    unsigned int m_turnIndex;

    /**
     * Playes a single turn for a player
     *
     * @param player - the player to play the turn for
     *
     * @return - void
    */
    void playTurn(Player& player);

    /**
     * Plays a single round of the game
     *
     * @return - void
    */
    void playRound();

    /**
     * Checks if the game is over
     *
     * @return - true if the game is over, false otherwise
    */
    bool isGameOver() const;

    void createPlayer(unique_ptr<Character> character, const string &name,const string& job);

    void readEvents(std::istream &eventsStream);

    void readPlayers(std::istream &playersStream);


    bool checkIfStop(Player& player) const;

    void add_Pack(std::istream& eventsStream);
    void processPack(std::istream& eventsStream, Pack& pack);

public:
    /**
     * Constructor of MatamStory class
     *
     * @param eventsStream - events input stream (file)
     * @param playersStream - players input stream (file)
     *
     * @return - MatamStory object with the given events and players
     *
    */
    MatamStory(std::istream& eventsStream, std::istream& playersStream);

    /**
     * Plays the entire game
     *
     * @return - void
    */
    void play();


};
