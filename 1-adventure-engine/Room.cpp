/* 
 * File:   Room.cpp
 * Author: rusty
 * 
 * Created on 23. září 2012, 13:25
 */

#include "Room.h"

using namespace std;

Room::Room(char* _description) : description(_description) {
    north = NULL;
    east = NULL;
    south = NULL;
    west = NULL;
    up = NULL;
    down = NULL;

    inventory = new Inventory();
}

Room::~Room() {

    for (multimap<string, Character*>::iterator it(npcs.begin()); it != npcs.end(); ++it) {
        delete it->second;
    }
    
    delete inventory;
}



ostream& operator << (std::ostream& os, Room& room) {
    os << room.description << endl;
    os << "There is " << *(room.inventory);

    return os;
}
