#include "Builder.h"
#include "Room.h"
#include "MyEndCondition.h"
#include "MyItems.h"

using namespace std;

Builder::Builder() :  world(new World()) { }


void Builder::addRoom(const char* roomID, const char* description, bool isDark) {
    bool result = rooms.insert(make_pair(roomID, &(world->createRoom(description, isDark)))).second;
    checkError(result, "Attempted to insert a duplicate room.");
}


void Builder::addWay(const char* roomFromID, const char* roomToID, const char* direction) {
    Room* fromRoom = lookup(rooms, roomFromID, "Attempted to make way from a nonexistant room.");
    Room* toRoom = lookup(rooms, roomToID, "Attempted to make way to a nonexistant room.");
    fromRoom->addWay(direction, *toRoom);
}


void Builder::addItem(const char *uniqueName, const char *description, bool isMovable) {
    handleItem(uniqueName, auto_ptr<Item>(new Item(description, isMovable)));
}

void Builder::addTorch(const char *uniqueName, const char *description) {
    handleItem(uniqueName, auto_ptr<Item>(new Torch(description, true, false)));
}

void Builder::handleItem(const char *name, auto_ptr<Item> item) {
    checkError(items.count(string(name)) == 0, "Attempted to create an item with duplicate ID.");
    items.insert(make_pair(name, item.release()));
    itemsPlaced[name] = false;
}


void Builder::addItemToRoom(const char *itemName, const char *roomID) {
    Room* room = lookup(rooms,roomID, "Attempted to add an item to a nonexistant room.");
    Item* item = lookup(items,itemName, "Attempted to add a nonexistant item to a room.");
    checkError(!itemsPlaced[itemName], "Attempted to put an item to multiple places.");
    room->addItem(string(itemName), *item);
    itemsPlaced[itemName] = true;
}

void Builder::addItemToPlayer(const char *itemName) {
    Item* item = lookup(items,itemName, "Attempted to add a nonexistant item to the player.");
    checkError(!itemsPlaced[itemName], "Attempted to give the player an item already placed elsewhere.");
    world->getPlayer().addItem(string(itemName), *item);
    itemsPlaced[itemName] = true;
}


void Builder::setGreeting(const char* worldGreeting) {
    world->setDescription(worldGreeting);
}


void Builder::addItemInRoomEnd(const char *itemName, const char *roomID, bool victorious) {
    Room* room = lookup(rooms,roomID, "Attempted to tie victory to a nonexistant room.");
    checkError(items.count(string(itemName)) > 0, "Attempted to tie victory to a nonexistant item.");
    world->addCondition(*(new ItemInRoomCondition(*room, itemName, victorious ? VICTORY : DEFEAT)));
}


gameptr Builder::exportGame() {
    checkError(!rooms.empty(), "Cannot create a game without rooms!");
    gameptr game(new Game(world));
    cleanUp();
    world.reset(new World());
    return game;
}


void Builder::checkError(bool assertTrue, const char *errMsg) {
    if(!assertTrue) {
        throw logic_error(string(errMsg));
    }
}


void Builder::cleanUp() {
    for(map<const string, bool>::iterator it = itemsPlaced.begin(); it != itemsPlaced.end(); ++it) {
        if(!it->second) {
            delete items[it->first];
        }
    }
    rooms.clear();
    items.clear();
    itemsPlaced.clear();
}


Builder::~Builder() {
    cleanUp();
}

