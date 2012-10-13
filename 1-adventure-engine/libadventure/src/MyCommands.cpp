#include <sstream>

#include "MyCommands.h"
#include "World.h"

using namespace std;

void MyCommandGo::commandExecute(istringstream& iss, ostream& os, World& world) {

    string destination;

    iss >> destination;

    if(destination.empty()) {
        os << "Where shall I go? Please specify." << endl;
        return;
    }

    try {
        world.getPlayer().goTo(destination);
    } catch (const char* error) {
        os << error << endl;
    }

}

void MyCommandTake::commandExecute(istringstream& iss, ostream& os, World& world) {

    string itemName;

    iss >> itemName;

    if(itemName.empty()) {
        os << "What shall I take? Please specify." << endl;
        return;
    }

    try{
        world.getPlayer().takeItem(itemName);
        os << "You have taken the " << itemName << "." << endl;
    } catch (const char* error) {
        os << error << endl;
    }

}

void MyCommandDrop::commandExecute(istringstream& iss, ostream& os, World& world) {

    string itemName;

    iss >> itemName;

    if(itemName.empty()) {
        os << "What shall I drop? Please specify." << endl;
        return;
    }

    try{
        world.getPlayer().dropItem(itemName);
        os << "You have dropped the " << itemName << "." << endl;
    } catch (const char* error) {
        os << error << endl;
    }

}

void MyCommandInventory::commandExecute(istringstream& iss, ostream& os, World& world) {

    world.getPlayer().listItems(os);

}

void MyCommandEcho::commandExecute(istringstream& iss, ostream& os, World& world) {

    os << echo << endl;

}

