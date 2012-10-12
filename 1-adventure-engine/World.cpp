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

    state = new State();
}

World::~World() {    

    for (list<Room*>::iterator it(rooms.begin()); it != rooms.end(); ++it) {
        delete *(it);
    }

    for (list<ICondition*>::iterator it(conditions.begin()); it != conditions.end(); ++it) {
        delete *(it);
    }

    delete startRoom;
    delete player;
    delete state;
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

void World::addCondition(ICondition& condition) {
    conditions.push_back(&condition);
}

const State& World::evaluateGameState() {

    for (list<ICondition*>::iterator it(conditions.begin()); it != conditions.end(); ++it) {
        state->nextState((*it)->testCondition(*this));
    }

    return *state;
}

ostream& operator << (std::ostream& os, World& world) {
    os << world.description;
    return os;
}
