
#include <ostream>
#include <string>

#include "Event.h"

#ifndef COMMAND_H
#define COMMAND_H

class ICommand {
public:

    virtual void execute(std::string, std::istringstream&, std::ostream&) = 0;

    virtual ~ICommand() {}

};

#endif // COMMAND_H
