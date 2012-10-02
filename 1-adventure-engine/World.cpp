/* 
 * File:   World.cpp
 * Author: rusty
 * 
 * Created on 23. září 2012, 15:39
 */

#include "World.h"
#include <string>

using namespace std;

World::~World() {    
    delete player;
    delete victoryCond;

    for (list<Room*>::iterator it(rooms.begin()); it != rooms.end(); ++it) {
        delete *(it);
    }
}

Room* World::registerRoom(Room* room) {
    rooms.push_back(room);
    return room;
}

ostream& operator << (std::ostream& os, World& world) {
    os << world.description;
    return os;
}
