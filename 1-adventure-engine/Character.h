/* 
 * File:   Character.h
 * Author: rusty
 *
 * Created on 23. září 2012, 13:53
 */

#include <ostream>
#include <string>

#include "Inventory.h"

#ifndef CHARACTER_H
#define	CHARACTER_H

class Room;

class Character {
public:
    Character(char* _name, char* description, Room* location);
    ~Character();
    
    char* name;
    Inventory* inventory;
    Room* location;
    
private:
    Character(const Character& orig) {}
    Character& operator = (const Character& orig) {return *this;}

    char* description;
};

#endif	/* CHARACTER_H */

