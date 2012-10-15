#include <sstream>

#include "MyCommands.h"
#include "World.h"

using namespace std;

void MyCommandGo::commandExecute(istringstream& iss, ostream& os, World& world) {

    world.getPlayer().goTo(getWord(iss, "Where shall I go? Please specify."));
    os << world.getPlayer();
}

void MyCommandTake::commandExecute(istringstream& iss, ostream& os, World& world) {

    string itemName = getWord(iss, "What shall I take? Please specify.");
    world.getPlayer().takeItem(itemName);
    os << "You have taken the " << itemName << "." << endl;
}

void MyCommandDrop::commandExecute(istringstream& iss, ostream& os, World& world) {

    string itemName = getWord(iss, "What shall I drop? Please specify.");
    world.getPlayer().dropItem(itemName);
    os << "You have dropped the " << itemName << "." << endl;
}

void MyCommandInventory::commandExecute(istringstream& iss, ostream& os, World& world) {

    world.getPlayer().listItems(os);
}

void MyCommandEcho::commandExecute(istringstream& iss, ostream& os, World& world) {

    os << echo << endl;
}

void MyCommandLook::commandExecute(istringstream& iss, ostream& os, World& world) {

    os << world.getPlayer();
}

void MyCommandLight::commandExecute(istringstream & iss, ostream & os, World & world) {

    Character& player = world.getPlayer();
    bool light = player.toggleLight();
    os << "Your light source is now " << (light ? "on" : "off") << "." << endl;
    if(world.getCurrentRoom().isDark()) {
        os << player;
    }
}
