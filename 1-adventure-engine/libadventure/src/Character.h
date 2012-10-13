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
    Character(const char* name, const char* description, Room& initLocation);
    ~Character();
    
    /**
     * Move character to a neighour location.
     */
    void goTo(std::string locationName);

    /**
     * Teleport character to any location.
     */
    void teleport(Room& location);

    /**
     * Get the charact's location.
     */
    Room& getLocation();

    /**
     * Take an item which is in character's location to the inventory.
     */
    void takeItem(std::string itemName);

    /**
     * Drop an item to the ground.
     */
    void dropItem(std::string itemName);

    /**
     * List character's inventory.
     */
    void listItems(std::ostream& os);

    friend std::ostream& operator << (std::ostream& os, Character& character);
    
private:
    Character(const Character& orig) : location(orig.location) {}
    Character& operator = (const Character& orig) {return *this;}

    const char* name;
    const char* description;

    Inventory* inventory;

    Room* location;
};

#endif	/* CHARACTER_H */

