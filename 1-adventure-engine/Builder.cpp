#include "Builder.h"
#include "Room.h"

using namespace std;

Builder::Builder()
{
}


bool Builder::addRoom(const std::string& roomName, const std::string& roomDescription) {
    return rooms.insert(make_pair(roomName, &(world->createRoom(roomDescription.c_str())))).second;
}


bool Builder::addWay(const std::string& roomFromName, const std::string& roomToName, const std::string& direction) {
    Room* fromRoom = lookupRoom(roomFromName);
    Room* toRoom = lookupRoom(roomToName);
    if(fromRoom == NULL || toRoom == NULL) {
        return false;
    }
    fromRoom->addWay(direction, *toRoom);
    return true;
}


bool Builder::addItemToRoom(const std::string& roomName, const std::string itemName, const std::string& itemDescription, bool isMovable) {
    Room* room = lookupRoom(roomName);
    if(!room) {
        return false;
    }
    room->getInventory().addItem(itemName,*(new Item(itemDescription.c_str(), isMovable))); // TODO Demeter!
    return true;
}

void Builder::setGreeting(const std::string worldGreeting) {
    world->setDescription(worldGreeting.c_str());
}


void Builder::setPlayer(const std::string& playerName, const std::string& playerDescription) {
    world->setPlayer(playerName.c_str(), playerDescription.c_str());
}

Room* Builder::lookupRoom(const string &name) {
    map<const std::string, Room*>::iterator it = rooms.find(name);
    return it == rooms.end() ? NULL : it->second;
}


// TODO victory condition interface

gameptr Builder::exportGame() {
    gameptr game(new Game(world));
    return game;
}

Builder::~Builder() { }

