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
#include "MyItems.h"


class Character : public AHasInventory {
public:
    Character(const char* name, const char* description, Room& initLocation);
    virtual ~Character();
    
    /**
     * Move character to a neighbour location.
     */
    void goTo(std::string locationName);

    /**
     * Teleport character to any location.
     */
    void teleport(Room& location);

    /**
     * Get the character's location.
     */
    Room& getLocation();

    /**
     * Attempt to switch the state of any light source the character might have.
     */
    bool toggleLight();

    /**
     * Returns true if the chatacter has an active light source.
     */
    bool emitsLight();

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

    friend std::ostream& operator << (std::ostream& os, Character& character);
    
private:

    void checkForLightSource(Item& item, bool incoming);
    void requireLight();

    Character(const Character& orig) : location(orig.location) {}
    Character& operator = (const Character& orig) {return *this;}

    const char* name;
    const char* description;

    Torch* lightSource;
    Inventory* inventory;

    Room* location;
};

#endif	/* CHARACTER_H */

