#ifndef MYENDCONDITION_H
#define MYENDCONDITION_H

#include "Condition.h"
#include "World.h"

class ItemInRoomCondition : public ICondition
{
public:
    ItemInRoomCondition(Room& _room, std::string _itemName, GameState _result) : room(_room), itemName(_itemName), result(_result) {}
    virtual ~ItemInRoomCondition() {}

    virtual GameState testCondition(World& world);

private:
    Room& room;
    std::string itemName;
    GameState result;
};

#endif // MYENDCONDITION_H
