
#include <ostream>
#include <string>

#include "Event.h"

#ifndef COMMAND_H
#define COMMAND_H

class ICommand {
public:

    virtual void execute(std::istringstream&, std::ostream&, World&) = 0;

    virtual ~ICommand() {}

};

#endif // COMMAND_H
