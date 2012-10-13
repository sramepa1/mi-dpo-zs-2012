/* 
 * File:   Character.h
 * Author: rusty
 *
 * Created on 23. září 2012, 13:53
 */
#ifndef CHARACTER_H
#define	CHARACTER_H

#include <ostream>
#include <string>

#include "Inventory.h"
#include "xCharacterRoom.h"


class Character {
public:
    Character(const char*, const char*, Room&);
    ~Character();
    
    void goTo(std::string);
    void teleport(Room& room);
    Room& getLocation();

    void takeItem(std::string);
    void dropItem(std::string);
    void listItems(std::ostream&);

    friend std::ostream& operator << (std::ostream&, Character&);
    
private:
    Character(const Character& orig) : location(orig.location) {}
    Character& operator = (const Character& orig) {return *this;}

    const char* name;
    const char* description;

    Inventory* inventory;

    Room* location;
};

#endif	/* CHARACTER_H */

