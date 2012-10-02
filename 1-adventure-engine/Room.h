/* 
 * File:   Room.h
 * Author: rusty
 *
 * Created on 23. září 2012, 13:25
 */

#include <ostream>
#include <map>
#include <string>

#include "Character.h"
#include "Item.h"

#ifndef ROOM_H
#define	ROOM_H

class Room {
public:
    
    Room(char* _description);
    ~Room();
    
    Room* north;
    Room* east;
    Room* south;
    Room* west;
    Room* up;
    Room* down;

    Inventory* inventory;
    
    friend std::ostream& operator << (std::ostream&, Room&);
    
private:
    Room(const Room& orig) {}
    Room& operator = (const Room& orig) {return *this;}
    
    char* description;

    std::multimap<std::string, Character*> npcs;

};

#endif	/* ROOM_H */

