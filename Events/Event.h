
#pragma once
#include "Monsters/Monster.h"
#include "../Players/Player.h"
#include <memory>

class Event {
public:
    Event(string event_name, string description = "");
    /**
     * Gets the description of the event
     *
     * @return - the description of the event
    */
    string getDescription() const;

protected:
    string event_name;
    string description;


};

class SpecialEvent: public Event {
public:
    SpecialEvent();
    
};

class Encounter: public Event {
private:
    unique_ptr<Monster> monster;
public:
    Encounter(Monster* monster);

};


class SolarEclipse : public SpecialEvent {
public:
};


class PotionsMerchant : public SpecialEvent {
public:
};
