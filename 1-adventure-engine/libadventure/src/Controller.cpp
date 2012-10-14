#include <cstring>
#include <string>
#include <sstream>

#include "Controller.h"

using namespace std;

Controller::Controller(istream& _is, ostream& _os, worldptr _world) : is(_is), os(_os), world(_world) {}

Controller::~Controller() {
    for (map<std::string, ICommand*>::iterator it(commands.begin()); it != commands.end(); ++it) {
        delete it->second;
    }
}

void Controller::addCommand(string text, ICommand* command) {
    if(text.compare("q") == 0) {
        throw "Invalid command text!";
    }

    commands.insert(pair<string, ICommand*> (text, command));
}

void Controller::run() {

    string commandName;
    os << *world << endl << world->getPlayer();

    for(;;) {
        istringstream commandStream(prompt("> "));
        commandName.clear();
        commandStream >> commandName;

        if(commandName.compare("q") == 0 || !continueGame(commands.find(commandName), commandStream)) {
            os << "Bye!" << endl;
            return;
        }
    }
}


string Controller::prompt(string prompt) {
    os << endl << prompt;
    string line;
    if(!getline(is, line)) {
        line.assign("q");   // EOF is interpreted as exit.
    }
    os << endl;
    return line;
}


bool Controller::continueGame(map<string, ICommand*>::iterator it, istringstream& commandStream) {
    if(it == commands.end()) {
        os << "Unknown command. Type \"help\" for command list." << endl;

    } else {
        const State& state = it->second->execute(commandStream, os, *world);

        if(state.isVictory()) {
            os << "Congratulations, you have won the game." << endl;
            return false;
        } else if(state.isDefeat()) {
            os << "Sorry, you have lost the game." << endl;
            return false;
        }
    }
    return true;
}
