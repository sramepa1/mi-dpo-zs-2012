/* 
 * File:   Room.cpp
 * Author: rusty
 * 
 * Created on 23. září 2012, 13:25
 */

#include "Room.h"

using namespace std;

Room::Room(const char* _description) : description(_description) {
    inventory = new Inventory();
}

Room::~Room() {

    for (multimap<string, Character*>::iterator it(npcs.begin()); it != npcs.end(); ++it) {
        delete it->second;
    }

    //cesty nemažu
    
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
        throw "There is no such way";
    }

    return it->second;
}


ostream& operator << (std::ostream& os, Room& room) {
    os << room.description << endl;
    os << "You can go";

    for(map<std::string, Room&>::iterator it = room.ways.begin(); it != room.ways.end(); ++it) {
        os << " " << it->first << ",";
    }

    os << endl << "There is " << *(room.inventory);

    return os;
}
