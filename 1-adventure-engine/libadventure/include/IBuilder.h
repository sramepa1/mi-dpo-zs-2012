#ifndef IBUILDER_H
#define IBUILDER_H

#include <string>
#include <tr1/memory>
#include <stdexcept>

#include "IGame.h"

class IBuilder
{
public:

    virtual void addRoom(const char* roomName, const char* roomDescription) =0;
    virtual void addWay(const char* roomFrom, const char* roomTo, const char* direction) =0;
    virtual void addItemToRoom(const char* roomName, const char* itemName, const char* itemDescription, bool isMovable) =0;

    virtual void setGreeting(const char* worldGreeting) =0;
    virtual void setPlayer(const char* playerName, const char* playerDescription) =0;

    // TODO victory condition interface

    virtual gameptr exportGame() =0;
};

typedef std::tr1::shared_ptr<IBuilder> builderptr;

#endif // IBUILDER_H
