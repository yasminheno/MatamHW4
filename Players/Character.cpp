
#include "Character.h"

string Responsible::getDescription() const {
    return "Responsible";
}

string RiskTaking::getDescription() const {
    return "RiskTaking";
}

Responsible *Responsible::clone() const {
    return new Responsible(*this);
}

RiskTaking *RiskTaking::clone() const {
    return new RiskTaking(*this);
}