#include "MyEvents.h"

using namespace std;

ShowRopeEvent::ShowRopeEvent(Room* _room) : room(_room) {}

void ShowRopeEvent::execute() {
    throw "todo resolve";
}


/*
MyEventNorth::execute(World* world) {
    character->location = character->location->north;
}

MyEventSouth::execute(World* world) {
    character->location = character->player->location->east;
}

MyEventWest::execute(World* world) {
    character->location = character->location->west;
}

MyEventEast::execute(World* world) {
    character->location = character->location->east;
}
*/
