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

class Room {
public:
    
    friend class World;

    /**
     * Get the room's inventory.
     */
    Inventory& getInventory();

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
    
    friend std::ostream& operator << (std::ostream&, Room&);
    
private:
    Room(const char* _description);
    ~Room();
    Room(const Room& orig) {}
    Room& operator = (const Room& orig) {return *this;}
    
    const char* description;

    std::map<std::string, Room&> ways;

    Inventory* inventory;

};

#endif	/* ROOM_H */

