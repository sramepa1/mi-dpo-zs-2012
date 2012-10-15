#include "Command.h"

using namespace std;

const State& ACommand::execute(istringstream& iss, ostream& os, World& world) {
    try {
        commandExecute(iss, os, world);
    } catch (const char* error) {
        os << error << endl;
    }
    return world.evaluateGameState();
}

string ACommand::getWord(istringstream &iss, const char* errMsg) {

    string word;
    iss >> word;
    if(word.empty()) {
        throw errMsg;
    }
    return word;
}
