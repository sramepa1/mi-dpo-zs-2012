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

    virtual void addRoom(const char* roomName, const char* roomDescription);
    virtual void addWay(const char* roomFrom, const char* roomTo, const char* direction);
    virtual void addItemToRoom(const char* roomName, const char* itemName, const char* itemDescription, bool isMovable);

    virtual void setGreeting(const char* worldGreeting);
    virtual void setPlayer(const char* playerName, const char* playerDescription);

    // TODO victory condition interface

    virtual gameptr exportGame();

    virtual ~Builder();

private:
    Builder(const Builder& orig) {}
    Builder& operator = (const Builder& orig) {return *this;}

    Room* lookupRoom(const char* name);
    void checkError(bool assertTrue, const char* errMsg);

    bool playerSet;
    std::string greeting;
    std::map<const std::string, Room*> rooms;
    worldptr world;

};

#endif // BUILDER_H
