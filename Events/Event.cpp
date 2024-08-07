#include "Event.h"
#include "string"
#include "Utilities.h"
using std::string;
 //_________________Event____________________________________________//
Event::Event(const string& event_name) : event_name(event_name) {};


//_________________Special Event__________________________________________//
SpecialEvent::SpecialEvent(const string &event_name) : Event(event_name) {};

string SolarEclipse::getDescription() const {
    return "SolarEclipse";
}

void SolarEclipse::applyEvent(Player &player) const {
    if(player.getJob() == "Magician")
    {
        player.setForce(player.getForce() + 1);
        player.checkOutCome(getSolarEclipseMessage(player,1));
    } else{
        player.setForce((player.getForce() -1 ) > 0 ? player.getForce() -1 : 0);
        player.checkOutCome(getSolarEclipseMessage(player, -1));
    }
}

SolarEclipse::SolarEclipse() : SpecialEvent("SolarEclipse"){};

string PotionsMerchant::getDescription() const {
    return "PostionsMerchant";
}

void PotionsMerchant::applyEvent(Player &player) const {
    int amount = 0;
    const int potion_price = 5;
    const int potion_raise = 10;
    if(player.getCharacter() == "Responsible") {
        while (player.canPlayerPay(potion_price) || player.check_adding_HP(potion_raise)){
            amount++;
            player.decreaseCoins(potion_price);
            player.addCurrentHP(potion_raise);
        }
        player.checkOutCome(getPotionsPurchaseMessage(player,amount));
    } else {
        if(player.getCurrentHP() < 50 &&
        player.canPlayerPay(potion_price) && player.check_adding_HP(potion_raise)){
            amount = 1;
            player.checkOutCome(getPotionsPurchaseMessage(player,amount));
            player.decreaseCoins(potion_price);
            player.addCurrentHP(potion_raise);
        }
    }
}

PotionsMerchant::PotionsMerchant() : SpecialEvent("PotionsMerchant"){};

//_________________Encounter________________________________________//
Encounter::Encounter(unique_ptr<Monster> monster) : Event("Encounter"),
monster(std::move(monster)){}


string Encounter::getDescription() const {
    return monster->getName() + "(power " + (std::to_string(monster->getCombatPower())) +
    + ", loot " + std::to_string(monster->getLoot()) +
    ", damage " + std::to_string(monster->getDamage())+")";
}

void Encounter::applyEvent(Player &player) const {
    if(player.getCombatPower() > monster->getCombatPower()) {
        player.levelUp();
        player.addCoins(monster->getLoot());
        player.checkOutCome(getEncounterWonMessage(player, monster->getLoot()));
        player.Weaken(10);
    } else {
        player.decreaseCurrentHP(monster->getDamage());
        player.checkOutCome(getEncounterLostMessage(player,monster->getDamage()));

    }
}
