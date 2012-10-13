#ifndef MYENDCONDITION_H
#define MYENDCONDITION_H

#include "World.h"

class ItemInRoomEndVictory : public ICondition
{
public:
    ItemInRoomEndVictory(Room& _room, std::string _itemName, GameState _result) : room(_room), itemName(_itemName), result(_result) {}
    virtual ~ItemInRoomEndVictory() {}

    virtual GameState testCondition(World&);

private:
    Room& room;
    std::string itemName;
    GameState result;
};

#endif // MYENDCONDITION_H
