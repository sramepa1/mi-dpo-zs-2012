#ifndef IBUILDER_H
#define IBUILDER_H

#include <string>
#include <tr1/memory>
#include <stdexcept>

#include "IGame.h"

class IBuilder
{
public:

    virtual void addRoom(const char* roomID, const char* description) =0;
    virtual void addWay(const char* roomFromID, const char* roomToID, const char* direction) =0;

    virtual void addItem(const char* uniqueName, const char* description, bool isMovable) =0;
    virtual void addItemToRoom(const char* roomID, const char* itemName) =0;

    virtual void addItemInRoomEnd(const char* itemName, const char* roomID, bool victorious) =0;

    virtual void setGreeting(const char* worldGreeting) =0;
    virtual void setPlayer(const char* name, const char* description) =0;

    virtual gameptr exportGame() =0;
};

typedef std::tr1::shared_ptr<IBuilder> builderptr;

#endif // IBUILDER_H
