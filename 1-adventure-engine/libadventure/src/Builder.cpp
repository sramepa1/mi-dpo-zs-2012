#include "Builder.h"
#include "Room.h"
#include "MyEndCondition.h"

using namespace std;

Builder::Builder() :  playerSet(false), world(new World())
{
}


void Builder::addRoom(const char* roomID, const char* description) {
    bool result = rooms.insert(make_pair(roomID, &(world->createRoom(description)))).second;
    checkError(result, "Attempted to insert a duplicate room.");
}


void Builder::addWay(const char* roomFromID, const char* roomToID, const char* direction) {
    Room* fromRoom = lookup(rooms, roomFromID, "Attempted to make way from a nonexistant room.");
    Room* toRoom = lookup(rooms, roomToID, "Attempted to make way to a nonexistant room.");
    fromRoom->addWay(direction, *toRoom);
}

void Builder::addItem(const char *uniqueName, const char *description, bool isMovable) {
    checkError(items.count(string(uniqueName)) == 0, "Attempted to create an item with duplicate ID.");
    items.insert(make_pair(uniqueName, new Item(description, isMovable)));
}

void Builder::addItemToRoom(const char *roomID, const char *itemName) {
    Room* room = lookup(rooms,roomID, "Attempted to add an item to a nonexistant room.");
    Item* item = lookup(items,itemName, "Attempted to add a nonexistant item to a room.");
    room->getInventory().addItem(string(itemName), *item);
}

void Builder::setGreeting(const char* worldGreeting) {
    world->setDescription(worldGreeting);
}

void Builder::setPlayer(const char* name, const char* description) {
    checkError(!playerSet, "Attempted to redefine player.");
    world->setPlayer(name, description);
    playerSet = true;
}

void Builder::addItemInRoomEnd(const char *roomID, const char *itemName, bool victorious) {
    Room* room = lookup(rooms,roomID, "Attempted to tie victory to a nonexistant room.");
    checkError(items.count(string(itemName)) > 0, "Attempted to tie victory to a nonexistant item.");
    world->addCondition(*(new ItemInRoomEndVictory(*room, itemName, victorious ? VICTORY : DEFEAT)));
}

gameptr Builder::exportGame() {
    checkError(!rooms.empty(), "Cannot create a game without rooms!");
    checkError(playerSet, "Cannot create a game without a player!");
    gameptr game(new Game(world));
    return game;
}

void Builder::checkError(bool assertTrue, const char *errMsg) {
    if(!assertTrue) {
        throw logic_error(string(errMsg));
    }
}

Builder::~Builder() { }

