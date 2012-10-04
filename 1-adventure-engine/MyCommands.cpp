#include <sstream>

#include "MyCommands.h"
#include "World.h"

using namespace std;
//TODO předělat na třídy
void MyCommandGo::execute(istringstream& iss, ostream& os) {

    string destination;

    iss >> destination;

    if(destination.empty()) {
        os << "Where shall I go? Please specify." << endl;
        return;
    }

    try {
        player->goTo(destination);
    } catch (const char* error) {
        os << error << endl;
    }

}

void MyCommandTake::execute(istringstream& iss, ostream& os) {

    string itemName;

    iss >> itemName;

    if(itemName.empty()) {
        os << "What shall I take? Please specify." << endl;
        return;
    }

    Item* item = player->getLocation().inventory->findItem(itemName);

    if(item == NULL) {
        os << "There is no such thing." << endl;
        return;
    }

    if(!item->isMovable) {
        os << "You can not take " << itemName << "." << endl;
        return;
    }

    player->inventory->addItem(itemName, item);
    player->getLocation().inventory->removeItem(itemName);

    os << "You have taken the " << itemName << "." << endl;

}

void MyCommandDrop::execute(istringstream& iss, ostream& os) {

    string itemName;

    iss >> itemName;

    if(itemName.empty()) {
        os << "What shall I drop? Please specify." << endl;
        return;
    }

    Item* item = player->inventory->findItem(itemName);

    if(item == NULL) {
        os << "I have no such thing." << endl;
        return;
    }

    if(!item->isMovable) {
        os << "You can not drop " << itemName << "." << endl;
        return;
    }

    player->inventory->removeItem(itemName);
    player->getLocation().inventory->addItem(itemName, item);

    os << "You have dropped the " << itemName << "." << endl;
}

void MyCommandInventory::execute(istringstream& iss, ostream& os) {

    os << "You have " << *(player->inventory);

}

/*
MyCommandSouth::execute(istringstream& iss, ostream& os) {
    Character* player = World::getInstance()->character;
    player->location = player->location->east;

    os << player->location;
}

MyCommandWest::execute(istringstream& iss, ostream& os) {
    Character* player = World::getInstance()->character;
    player->location = player->location->west;

    os << player->location;
}

MyCommandEast::execute(istringstream& iss, ostream& os) {
    Character* player = World::getInstance()->character;
    player->location = player->location->east;

    os << player->location;
}
*/
