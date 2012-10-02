#include "MyEvents.h"

using namespace std;

ShowRopeEvent::ShowRopeEvent(Room* _room) : room(_room) {}

void ShowRopeEvent::execute() {
    room->inventory->addItem("rope",new Item("loking safely enought to clib it up"));
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
