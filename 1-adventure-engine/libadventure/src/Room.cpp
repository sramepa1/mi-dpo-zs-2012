/* 
 * File:   Room.cpp
 * Author: rusty
 * 
 * Created on 23. září 2012, 13:25
 */

#include "Room.h"

using namespace std;

Room::Room(const char* _description, bool isDark) : description(_description), dark(isDark) {
    inventory = new Inventory();
}

Room::~Room() {
    delete inventory;
}

void Room::addWay(string name, Room& room) {
    ways.insert(pair<string, Room&> (name, room));
}

void Room::removeWay(string name) {
    map<std::string, Room&>::iterator it = ways.find(name);

    if(it == ways.end()) {
        return;
    }

    ways.erase(it);
}

Room& Room::findWay(string name) {
    map<std::string, Room&>::iterator it = ways.find(name);

    if(it == ways.end()) {
        throw "You can't go that way.";
    }

    return it->second;
}

bool Room::isDark() {
    return dark;
}

bool Room::isIlluminated(Character &player) {
    return dark ? player.emitsLight() : true;
}

void Room::addItem(string itemName, Item& item) {
    inventory->addItem(itemName, item);
}

void Room::removeItem(string itemName) {
    inventory->removeItem(itemName);
}

Item& Room::findItem(string itemName) {
    return inventory->findItem(itemName);
}

ostream& operator << (std::ostream& os, Room& room) {
    os << room.description << endl;
    if(!room.ways.empty()) {
        os << "You can go ";
        map<std::string, Room&>::iterator it = room.ways.begin();
        os << it->first;
        for(++it; it != room.ways.end(); ++it) {
            os << ", " << it->first;
        }
        os << "." << endl;
    }
    if(!room.inventory->isEmpty()) {
        os << "You see: " << endl << *(room.inventory);
    }
    return os;
}
