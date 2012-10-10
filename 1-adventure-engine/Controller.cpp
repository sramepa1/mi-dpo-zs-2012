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

    for (list<IEvent*>::iterator it(events.begin()); it != events.end(); ++it) {
        delete *(it);
    }
}

void Controller::addCommand(string text, ICommand* command) {
    if(text.compare("q") == 0) {
        throw "Invalid command text!";
    }

    commands.insert(pair<string, ICommand*> (text, command));
}

void Controller::addEvent(IEvent* event) {
    events.push_back(event);
}

void Controller::run() {

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

            //TODO lépe ... a asy je blbě iterátor (znevalidní se)
            /*
            for(list<IEvent*>::iterator lit(events.begin()); lit != events.end(); lit++) {
                (*lit)->execute();
                if(!(*lit)->keepAlive()) {
                    delete *(lit);
                    events.erase(lit);
                }
            }*/

            os << endl << world->getPlayer().getLocation();
        }

        os << "> ";
    }
}
