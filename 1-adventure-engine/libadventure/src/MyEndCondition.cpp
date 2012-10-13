#include "MyEndCondition.h"

GameState ItemInRoomEndVictory::testCondition(World& world) {
    try {
        room.getInventory().findItem(itemName);
        return result;
    } catch(const char* error) {
        return RUNNING;
    }
}
