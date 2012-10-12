#ifndef CONTROLLER_H
#define CONTROLLER_H

#include <istream>
#include <list>
#include <map>
#include <ostream>
#include <string>

#include "Command.h"
#include "Event.h"
#include "World.h"


class Controller {
public:
    Controller(std::istream&, std::ostream&, World&);
    ~Controller();

    void addCommand(std::string, ICommand*);
    void addEvent(IEvent*);

    void run();

private:
    std::istream& is;
    std::ostream& os;

    std::map<std::string, ICommand*> commands;
    std::list<IEvent*> events;
    World* world;

};

#endif // CONTROLLER_H
