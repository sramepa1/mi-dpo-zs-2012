
#include <ostream>
#include <string>

#include "Event.h"

#ifndef COMMAND_H
#define COMMAND_H

enum GameState {
    RUNNING, VICOTRY
};

class ICommand {
public:

    virtual void execute(std::istringstream&, std::ostream&, World&) = 0;
    virtual GameState commandExecute(std::istringstream&, std::ostream&, World&);

    virtual ~ICommand() {}

};

#endif // COMMAND_H
