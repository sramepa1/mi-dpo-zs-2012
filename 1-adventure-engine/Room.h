/*
 * File:   Room.h
 * Author: rusty
 *
 * Created on 23. září 2012, 13:25
 */

#include <ostream>
#include <map>
#include <string>

#include "Inventory.h"
#include "xCharecterRoom.h"


#ifndef ROOM_H
#define	ROOM_H

class World;

class Room {
public:
    
    friend class World;

    Inventory& getInventory();

    void addWay(std::string, Room&);
    void removeWay(std::string);
    Room& findWay(std::string);
    
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

