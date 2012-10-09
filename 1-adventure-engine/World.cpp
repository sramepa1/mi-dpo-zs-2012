/* 
 * File:   World.cpp
 * Author: rusty
 * 
 * Created on 23. září 2012, 15:39
 */

#include "World.h"
#include <string>

using namespace std;

World::World(const WorldInit& init) {
    description = init.worldDescription;
    vicotryMessage = init.vicotryMessage;
    startRoom = new Room(init.startRoomDescription);
    player = new Character(init.playerName, init.playerDescription, *startRoom);
}

World::~World() {    
    delete player;
    delete victoryCond;

    for (list<Room*>::iterator it(rooms.begin()); it != rooms.end(); ++it) {
        delete *(it);
    }

    delete startRoom;
}

Room& World::getStartRoom() {
    return *startRoom;
}

Character& World::getPlayer() {
    return *player;
}

Room& World::createRoom(const char* description) {

    Room* room = new Room(description);

    rooms.push_back(room);

    return *room;
}

void World::addVictoryCondition(ICondition& condition) {
    victoryCondition.push_back(&condition);
}

bool World::testVictory() {

    for (list<ICondition*>::iterator it(victoryConditions.begin()); it != victoryConditions.end(); ++it) {
        if(it->testCondition(*this) == VICOTRY) {
            description = vicotryMessage;
            return true;
        }
    }

    return false;
}

ostream& operator << (std::ostream& os, World& world) {
    os << world.description;
    return os;
}
