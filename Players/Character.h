#pragma once
#include "string"
using std::string;


class Character{
public:

    virtual ~Character() = default;
    virtual string getDescription() const = 0;
    virtual Character* clone() const = 0;

};

class Responsible : public Character{
public:
    Responsible() = default;
    string getDescription() const override;
    Responsible* clone() const override;
};

class RiskTaking : public Character{
public:
    RiskTaking() = default;
    string getDescription() const override;
    RiskTaking* clone() const override;
};
