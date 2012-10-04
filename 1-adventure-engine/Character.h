/* 
 * File:   Character.h
 * Author: rusty
 *
 * Created on 23. září 2012, 13:53
 */

#include <ostream>
#include <string>

#include "Inventory.h"
#include "xCharecterRoom.h"

#ifndef CHARACTER_H
#define	CHARACTER_H

class Character {
public:
    Character(const char*, const char*, Room&);
    ~Character();
    
    const char* name;
    Inventory* inventory;

    void goTo(std::string);
    Room& getLocation();

    friend std::ostream& operator << (std::ostream&, Character&);
    
private:
    Character(const Character& orig) : location(orig.location) {}
    Character& operator = (const Character& orig) {return *this;}

    const char* description;
    Room* location;
};

#endif	/* CHARACTER_H */

