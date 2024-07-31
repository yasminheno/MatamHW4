
#pragma once

#include "../Players/Player.h"

class Event {
public:
    Event(string event_name, string description = "");
    /**
     * Gets the description of the event
     *
     * @return - the description of the event
    */
    string getDescription() const;

private:
    string event_name;
    string description;


};
