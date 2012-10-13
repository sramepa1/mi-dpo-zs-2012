#ifndef BUILDER_H
#define BUILDER_H

#include <map>

#include "IBuilder.h"
#include "Room.h"
#include "World.h"
#include "Game.h"
#include "Condition.h"

class Builder : public IBuilder
{
public:
    Builder();

    virtual void addRoom(const char* roomID, const char* description);
    virtual void addWay(const char* roomFromID, const char* roomToID, const char* direction);

    virtual void addItem(const char* uniqueName, const char* description, bool isMovable);
    virtual void addItemToRoom(const char* roomID, const char* itemName);

    virtual void addItemInRoomEnd(const char* roomID, const char* itemName, bool victorious);

    virtual void setGreeting(const char* worldGreeting);
    virtual void setPlayer(const char* name, const char* description);

    virtual gameptr exportGame();

    virtual ~Builder();

private:
    Builder(const Builder& orig) {}
    Builder& operator = (const Builder& orig) {return *this;}

    void checkError(bool assertTrue, const char* errMsg);

    bool playerSet;
    std::string greeting;
    std::map<const std::string, Room*> rooms;
    std::map<const std::string, Item*> items;
    worldptr world;

    template<typename T> T* lookup(std::map<const std::string, T*>& container, const char* name, const char* errMsg) {
        typename std::map<const std::string, T*>::iterator it = container.find(name);
        checkError(it != container.end(), errMsg);
        return it->second;
    }
};

#endif // BUILDER_H
