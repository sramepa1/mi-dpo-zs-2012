#ifndef BUILDER_H
#define BUILDER_H

#include <map>

#include "IBuilder.h"
#include "Room.h"
#include "World.h"
#include "Game.h"
#include "Condition.h"

/**
 * Builder implementation. See IBuilder.h for public method documentation.
 */

class Builder : public IBuilder
{
public:
    Builder();

    virtual void addRoom(const char* roomID, const char* description);
    virtual void addWay(const char* roomFromID, const char* roomToID, const char* direction);

    virtual void addItem(const char* uniqueName, const char* description, bool isMovable);
    virtual void addItemToRoom(const char* itemName, const char* roomID);

    virtual void addItemInRoomEnd(const char* itemName, const char* roomID, bool victorious);

    virtual void setGreeting(const char* worldGreeting);

    virtual gameptr exportGame();

    virtual ~Builder();

private:
    Builder(const Builder& orig) {}
    Builder& operator = (const Builder& orig) {return *this;}

    void checkError(bool assertTrue, const char* errMsg);
    void cleanUp();

    std::string greeting;
    std::map<const std::string, Room*> rooms;
    std::map<const std::string, Item*> items;
    std::map<const std::string, bool> itemsPlaced;
    worldptr world;

    template<typename T> T* lookup(std::map<const std::string, T*>& container, const char* name, const char* errMsg) {
        typename std::map<const std::string, T*>::iterator it = container.find(name);
        checkError(it != container.end(), errMsg);
        return it->second;
    }
};

#endif // BUILDER_H
