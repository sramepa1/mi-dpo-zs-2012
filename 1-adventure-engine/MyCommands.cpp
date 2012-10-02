#include <sstream>

#include "MyCommands.h"
#include "World.h"

using namespace std;
//TODO předělat na třídy
void MyCommandGo::execute(string command, istringstream& iss, ostream& os) {

    Room* nextLocation;

    if(command.compare("n") == 0) {
        nextLocation = player->location->north;
        goto locationTest;
    }
    if(command.compare("s") == 0) {
        nextLocation = player->location->south;
        goto locationTest;
    }
    if(command.compare("e") == 0) {
        nextLocation = player->location->east;
        goto locationTest;
    }
    if(command.compare("w") == 0) {
        nextLocation = player->location->west;
    }

    locationTest:

    if(nextLocation == NULL) {
        os << "You can not go that direction." << endl;
    } else {
        player->location = nextLocation;
    }

}

void MyCommandTake::execute(string command, istringstream& iss, ostream& os) {

    string itemName;

    iss >> itemName;

    if(itemName.empty()) {
        os << "What shall I take? Please specify." << endl;
        return;
    }

    Item* item = player->location->inventory->findItem(itemName);

    if(item == NULL) {
        os << "There is no such thing." << endl;
        return;
    }

    if(!item->isMovable) {
        os << "You can not take " << itemName << "." << endl;
        return;
    }

    player->inventory->addItem(itemName, item);
    player->location->inventory->removeItem(itemName);

    os << "You have taken the " << itemName << "." << endl;

}

void MyCommandDrop::execute(string command, istringstream& iss, ostream& os) {

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
    player->location->inventory->addItem(itemName, item);

    os << "You have dropped the " << itemName << "." << endl;
}

void MyCommandInventory::execute(string command, istringstream& iss, ostream& os) {

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
