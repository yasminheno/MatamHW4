
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
     * @return - the description of the e
    */
    virtual string getDescription() const;

protected:
    string event_name;
    string description;


};

class SpecialEvent: public Event {
public:
    SpecialEvent();
    string getDescription() const override;

};

class Encounter: public Event {
private:
    unique_ptr<Monster> monster;
public:
    Encounter(Monster* monster);
    string getDescription() const override;

};


class SolarEclipse : public SpecialEvent {
public:
    string getDescription() const override;
};


class PotionsMerchant : public SpecialEvent {
public:
    string getDescription() const override;
};
