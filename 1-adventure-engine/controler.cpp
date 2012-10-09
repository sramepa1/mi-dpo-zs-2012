#include <cstring>
#include <string>
#include <sstream>

#include "controler.h"

using namespace std;

Controler::Controler(istream& _is, ostream& _os, World& _world) : is(_is), os(_os), world(&_world) {}

Controler::~Controler() {
    for (map<std::string, ICommand*>::iterator it(commands.begin()); it != commands.end(); ++it) {
        delete it->second;
    }

    for (list<IEvent*>::iterator it(events.begin()); it != events.end(); ++it) {
        delete *(it);
    }
}

void Controler::addCommand(string text, ICommand* command) {
    if(text.compare("q") == 0) {
        throw "Invalid command text!";
    }

    commands.insert(pair<string, ICommand*> (text, command));
}

void Controler::addEvent(IEvent* event) {
    events.push_back(event);
}

void Controler::run() {

    os << *world << endl;
    os << world->getStartRoom();
    os << "> ";

    string line;

    while(getline(is, line)) {
        istringstream iss(line);
        string command;

        iss >> command;

        if(command.compare("q") == 0) {
            os << "Bye!" << endl;
            return;
        }

        map<string, ICommand*>::iterator mit = commands.find(command);

        if(mit == commands.end()) {
            os << "Unknown command. Type \"help\" for command list." << endl;
        } else {

            mit->second->execute(iss, os, *world);

            //TODO move to abstract class so executu would return victory state
            if(world->testVictory()) {
                os << (*world) << endl;
                break;
            }

            os << endl << world->getPlayer();
        }

        os << "> ";
    }
}
