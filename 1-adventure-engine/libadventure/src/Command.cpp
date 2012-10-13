#include "Command.h"

const State& ACommand::execute(std::istringstream& iss, std::ostream& os, World& world) {

    commandExecute(iss, os, world);

    return world.evaluateGameState();

}
