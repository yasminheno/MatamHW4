#include "string"
using std::string;



class Job{
    string job_type;
public:
    Job() = default;
    Job(string& job_type);
    virtual ~Job() = default;
    virtual string getDescription() const;
};

class Warrior : public Job{
public:
    Warrior();
    string getDescription() const override;

};

class Archer : public Job {
public:
    Archer();

    string getDescription() const override;
};


class Magician : public Job{
public:
    Magician();
    string getDescription() const override;
};





