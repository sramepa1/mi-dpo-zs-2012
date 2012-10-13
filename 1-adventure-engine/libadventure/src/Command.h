#ifndef COMMAND_H
#define COMMAND_H

#include <ostream>
#include <string>

#include "State.h"
#include "World.h"

class ICommand {
public:

    /**
     * Executes an command which determines new game state.
     */
    virtual const State& execute(std::istringstream& is, std::ostream& os, World& world) = 0;

    virtual ~ICommand() {}

};

class ACommand : public ICommand {
public:

    /**
     * Executes an command and automaticaly determines the game state
     */
    virtual const State& execute(std::istringstream& is, std::ostream& os, World& world);

    /**
     * Executes a simple command.
     */
    virtual void commandExecute(std::istringstream& is, std::ostream& os, World& world) = 0;

    virtual ~ACommand() {}

};

#endif // COMMAND_H
