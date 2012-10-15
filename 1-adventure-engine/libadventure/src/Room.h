/*
 * File:   Room.h
 * Author: rusty
 *
 * Created on 23. září 2012, 13:25
 */
#ifndef ROOM_H
#define	ROOM_H

#include <ostream>
#include <map>
#include <string>

#include "Inventory.h"
#include "xCharacterRoom.h"


class World;

class Room : public AHasInventory{
public:
    
    friend class World;

    /**
     * Add a way to another room.
     */
    void addWay(std::string directionName, Room& room);

    /**
     * Remove a way to another room.
     */
    void removeWay(std::string directionName);

    /**
     * Find a way to another room. If not found then method throws a const char* exception.
     */
    Room& findWay(std::string directionName);

    /**
     * Returns true if the room is considered dark and needs a light source to interact.
     */
    bool isDark();

    /**
     * Returns true if there is enough light in this room to interact.
     */
    bool isIlluminated(Character& player);
    
    /**
     * Add an item to the inventory.
     */
    virtual void addItem(std::string itemName, Item& item);

    /**
     * Remove an item from the inventory.
     */
    virtual void removeItem(std::string itemName);

    /**
     * Find an item in the inventory. If not found then method throws an const char* exception.
     */
    virtual Item& findItem(std::string itemName);

    friend std::ostream& operator << (std::ostream&, Room&);
    
private:
    Room(const char* _description, bool isDark);
    virtual ~Room();
    Room(const Room& orig) {}
    Room& operator = (const Room& orig) {return *this;}
    
    const char* description;
    bool dark;

    std::map<std::string, Room&> ways;

    Inventory* inventory;

};

#endif	/* ROOM_H */

