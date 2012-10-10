#ifndef BUILDER_H
#define BUILDER_H

#include <map>

#include "IBuilder.h"
#include "Room.h"
#include "World.h"
#include "Game.h"

class Builder : public IBuilder
{
public:
    Builder();

    virtual bool addRoom(const std::string& roomName, const std::string& roomDescription);
    virtual bool addWay(const std::string& roomFrom, const std::string& roomTo, const std::string& direction);
    virtual bool addItemToRoom(const std::string& roomName, const std::string itemName, const std::string& itemDescription, bool isMovable);

    virtual void setGreeting(const std::string worldGreeting);
    virtual void setPlayer(const std::string& playerName, const std::string& playerDescription);

    // TODO victory condition interface

    virtual gameptr exportGame();

    virtual ~Builder();

private:
    Builder(const Builder& orig) {}
    Builder& operator = (const Builder& orig) {return *this;}

    Room* lookupRoom(const std::string& name);

    std::string greeting;
    std::map<const std::string, Room*> rooms;
    worldptr world;

};

#endif // BUILDER_H
