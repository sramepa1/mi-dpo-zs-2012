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
        Character& player = world.getPlayer();

        player.getLocation().getInventory().moveItemTo(itemName, player.getInventory());
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
        Character& player = world.getPlayer();

        player.getInventory().moveItemTo(itemName, player.getLocation().getInventory());
        os << "You have dropped the " << itemName << "." << endl;

    } catch (const char* error) {
        os << error << endl;
    }

}

void MyCommandInventory::commandExecute(istringstream& iss, ostream& os, World& world) {

    os << "You have " << world.getPlayer().getInventory();

}

void MyCommandEcho::commandExecute(istringstream& iss, ostream& os, World& world) {

    os << echo << endl;

}

