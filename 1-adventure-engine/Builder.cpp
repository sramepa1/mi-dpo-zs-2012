#include "Builder.h"
#include "Room.h"

using namespace std;

Builder::Builder() : world(new World())
{
}


bool Builder::addRoom(const char* roomName, const char* roomDescription) {
    return rooms.insert(make_pair(roomName, &(world->createRoom(roomDescription)))).second;
}


bool Builder::addWay(const char* roomFromName, const char* roomToName, const char* direction) {
    Room* fromRoom = lookupRoom(roomFromName);
    Room* toRoom = lookupRoom(roomToName);
    if(fromRoom == NULL || toRoom == NULL) {
        return false;
    }
    fromRoom->addWay(direction, *toRoom);
    return true;
}


bool Builder::addItemToRoom(const char* roomName, const char* itemName, const char* itemDescription, bool isMovable) {
    Room* room = lookupRoom(roomName);
    if(!room) {
        return false;
    }
    room->getInventory().addItem(itemName,*(new Item(itemDescription, isMovable))); // TODO Demeter!
    return true;
}

void Builder::setGreeting(const char* worldGreeting) {
    world->setDescription(worldGreeting);
}


void Builder::setPlayer(const char* playerName, const char* playerDescription) {
    world->setPlayer(playerName, playerDescription);
}

Room* Builder::lookupRoom(const char* name) {
    map<const std::string, Room*>::iterator it = rooms.find(name);
    return it == rooms.end() ? NULL : it->second;
}


// TODO victory condition interface

gameptr Builder::exportGame() {
    gameptr game(new Game(world));
    return game;
}

Builder::~Builder() { }

