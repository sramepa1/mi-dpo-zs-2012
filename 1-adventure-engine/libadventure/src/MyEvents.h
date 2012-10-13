#ifndef MYEVENTS_H
#define MYEVENTS_H

#include <ostream>

#include "Event.h"
#include "Room.h"


class ShowRopeEvent : public IEvent {
public:
    ShowRopeEvent(Room*);
    virtual void execute();
private:
    Room* room;
};

#endif // MYEVENTS_H

