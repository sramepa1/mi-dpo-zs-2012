#include "MyEndCondition.h"

GameState ItemInRoomCondition::testCondition(World& world) {
    try {
        room.findItem(itemName);
        return result;
    } catch(const char* error) {
        return RUNNING;
    }
}
