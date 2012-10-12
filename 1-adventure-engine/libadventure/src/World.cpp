/* 
 * File:   World.cpp
 * Author: rusty
 * 
 * Created on 23. září 2012, 15:39
 */

#include "World.h"
#include <string>

using namespace std;

World::World() : description(NULL), startRoom(NULL), player(NULL) { }

World::~World() {    
    delete player;
    delete victoryCond;

    for (list<Room*>::iterator it(rooms.begin()); it != rooms.end(); ++it) {
        delete *(it);
    }
}

Room& World::getStartRoom() {
    return *startRoom;
}

Character& World::getPlayer() {
    return *player;
}

Room& World::createRoom(const char* description) {

    Room* room = new Room(description);
    if(startRoom == NULL) {
        startRoom = room;
        if(player != NULL) {
            player->teleport(*room);
        }
    }
    rooms.push_back(room);
    return *room;
}

void World::setDescription(const char* _description) {
    description = _description;
}

void World::setPlayer(const char* playerName, const char* playerDesc) {
    player = new Character(playerName,playerDesc, *startRoom);
}

ostream& operator << (std::ostream& os, World& world) {
    os << world.description;
    return os;
}
