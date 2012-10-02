#include <ostream>

#include "Event.h"
#include "Room.h"

#ifndef MYEVENTS_H
#define MYEVENTS_H

class ShowRopeEvent : public IEvent {
public:
    ShowRopeEvent(Room*);
    virtual void execute();
private:
    Room* room;
};

#endif // MYEVENTS_H

