#pragma once
#include "Event.h"
#include "string"
using std::string;

Event::Event(const string& event_name) : event_name(event_name) {};

SpecialEvent::SpecialEvent(const string &event_name) : Event(event_name) {};

string SolarEclipse::getDescription() const {
    return "SolarEclipse";
}


string PotionsMerchant::getDescription() const {
    return "PostionsMerchant";
}

Encounter::Encounter(unique_ptr<Monster> monster) : Event("Encounter"),
monster(std::move(monster)){}


string Encounter::getDescription() const {
    return monster->getName() + "(power " + (std::to_string(monster->getCombatPower())) +
    + ", loot " + std::to_string(monster->getLoot()) +
    ", damage " + std::to_string(monster->getDamage())+")";
}
