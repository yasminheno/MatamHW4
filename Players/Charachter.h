#include "string"
using std::string;


class Character{
public:
    virtual ~Character() = default;
    virtual string getDescription() const = 0;

};

class Responsible : public Character{
public:
    string getDescription() const override;
};

class Risktaking : public Character{
public:
    string getDescription() const override;
};
