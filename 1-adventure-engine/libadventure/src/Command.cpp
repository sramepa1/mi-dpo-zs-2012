#include "Command.h"

using namespace std;

const State& ACommand::execute(istringstream& iss, ostream& os, World& world) {
    commandExecute(iss, os, world);
    return world.evaluateGameState();
}
