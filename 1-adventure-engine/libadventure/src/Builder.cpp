#include "Builder.h"
#include "Room.h"

using namespace std;

Builder::Builder() :  playerSet(false), world(new World())
{
}


void Builder::addRoom(const char* roomName, const char* roomDescription) {
    bool result = rooms.insert(make_pair(roomName, &(world->createRoom(roomDescription)))).second;
    checkError(result, "Attempted to insert a duplicate room.");
}


void Builder::addWay(const char* roomFromName, const char* roomToName, const char* direction) {
    Room* fromRoom = lookupRoom(roomFromName);
    Room* toRoom = lookupRoom(roomToName);
    checkError(fromRoom != NULL, "Attempted to make way from a nonexistant room.");
    checkError(toRoom != NULL, "Attempted to make way to a nonexistant room.");
    fromRoom->addWay(direction, *toRoom);
}


void Builder::addItemToRoom(const char* roomName, const char* itemName, const char* itemDescription, bool isMovable) {
    Room* room = lookupRoom(roomName);
    checkError(room != NULL, "Attempted to add an item to a nonexistant room.");
    room->getInventory().addItem(itemName,*(new Item(itemDescription, isMovable))); // TODO Demeter!
}

void Builder::setGreeting(const char* worldGreeting) {
    world->setDescription(worldGreeting);
}


void Builder::setPlayer(const char* playerName, const char* playerDescription) {
    checkError(!playerSet, "Attempted to redefine player.");
    world->setPlayer(playerName, playerDescription);
    playerSet = true;
}

Room* Builder::lookupRoom(const char* name) {
    map<const std::string, Room*>::iterator it = rooms.find(name);
    return it == rooms.end() ? NULL : it->second;
}


// TODO victory condition interface

gameptr Builder::exportGame() {
    checkError(!rooms.empty(), "Cannot create a game with no rooms!");
    checkError(playerSet, "Cannot create a game with no player!");
    gameptr game(new Game(world));
    return game;
}

void Builder::checkError(bool assertTrue, const char *errMsg) {
    if(!assertTrue) {
        throw logic_error(string(errMsg));
    }
}

Builder::~Builder() { }

