#ifndef COMMAND_H
#define COMMAND_H

#include <ostream>
#include <string>

#include "Event.h"
#include "State.h"
#include "World.h"

class ICommand {
public:

    virtual const State& execute(std::istringstream&, std::ostream&, World&) = 0;

    virtual ~ICommand() {}

};

class ACommand : public ICommand {
public:

    virtual const State& execute(std::istringstream&, std::ostream&, World&);
    virtual void commandExecute(std::istringstream&, std::ostream&, World&) = 0;

    virtual ~ACommand() {}

};

#endif // COMMAND_H
