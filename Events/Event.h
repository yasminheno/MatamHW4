
#pragma once
#include "Monsters/Monster.h"
#include "Players/Player.h"
#include <memory>
#include "string"
using std::string;

class Event {
public:
   explicit Event(const string& event_name);
    /**
     * Gets the description of the event
     *
     * @return - the description of the event
    */
    virtual string getDescription() const = 0;
    virtual ~Event() = default;
    virtual void applyEvent(Player &player) const = 0;

protected:
    string event_name;
};

///////////////////////////////////////////////////////////////////////////

class SpecialEvent: public Event {
public:
    explicit SpecialEvent(const string& event_name);
    string getDescription() const override = 0;

};

class SolarEclipse : public SpecialEvent {
public:
    SolarEclipse();
    string getDescription() const override;
    void applyEvent(Player& player) const override;
};


class PotionsMerchant : public SpecialEvent {
public:
    PotionsMerchant();
    string getDescription() const override;
    void applyEvent(Player& player) const override;
};

///////////////////////////////////////////////////////////////////////////

class Encounter: public Event {
private:
    unique_ptr<Monster> monster;
public:
    explicit Encounter(unique_ptr<Monster> monster);
    string getDescription() const override;
    void applyEvent(Player& player) const override;

};


