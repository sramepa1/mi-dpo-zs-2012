#include <cstring>
#include <string>
#include <sstream>

#include "controler.h"

using namespace std;

Controler::Controler(istream& _is, ostream& _os, World* _world) : is(_is), os(_os), world(_world) {}

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
    os << *(world->startRoom);
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

            mit->second->execute(command, iss, os);

            //TODO lépe ... a asy je blbě iterátor (znevalidní se)
            for(list<IEvent*>::iterator lit(events.begin()); lit != events.end(); lit++) {
                (*lit)->execute();
                if(!(*lit)->keepAlive()) {
                    delete *(lit);
                    events.erase(lit);
                }
            }

            os << endl << *(world->player->location);

            //TODO otestovat wining condition
        }

        os << "> ";
    }
}
