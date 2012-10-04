#include <istream>
#include <list>
#include <map>
#include <ostream>
#include <string>

#include "Command.h"
#include "Event.h"
#include "World.h"

#ifndef CONTROLER_H
#define CONTROLER_H

class Controler {
public:
    Controler(std::istream&, std::ostream&, World&);
    ~Controler();

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

#endif // CONTROLER_H
