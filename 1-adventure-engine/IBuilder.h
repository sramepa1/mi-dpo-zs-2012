#ifndef IBUILDER_H
#define IBUILDER_H

#include <string>
#include <tr1/memory>

#include "IGame.h"

class IBuilder
{
public:

    virtual bool addRoom(const std::string& roomName, const std::string& roomDescription) =0;
    virtual bool addWay(const std::string& roomFrom, const std::string& roomTo, const std::string& direction) =0;
    virtual bool addItemToRoom(const std::string& roomName, const std::string itemName, const std::string& itemDescription, bool isMovable) =0;

    virtual void setGreeting(const std::string worldGreeting) =0;
    virtual void setPlayer(const std::string& playerName, const std::string& playerDescription) =0;

    // TODO victory condition interface

    virtual gameptr exportGame() =0;
};

typedef std::tr1::shared_ptr<IBuilder> builderptr;

#endif // IBUILDER_H
