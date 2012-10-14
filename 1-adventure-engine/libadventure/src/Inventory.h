/* 
 * File:   Inventory.h
 * Author: rusty
 *
 * Created on 23. září 2012, 13:47
 */
#ifndef INVENTORY_H
#define	INVENTORY_H

#include <map>
#include <ostream>
#include <string>

#include "Item.h"

class Item;

class AHasInventory {
public:
    virtual ~AHasInventory() {}

    /**
     * Add an item to the inventory.
     */
    virtual void addItem(std::string itemName, Item& item) = 0;

    /**
     * Remove an item from the inventory.
     */
    virtual void removeItem(std::string itemName) = 0;

    /**
     * Find an item in the inventory. If not found then method throws an const char* exception.
     */
    virtual Item& findItem(std::string itemName) = 0;

    /**
     * Move an item to another target's inventory. If not found then method throws a const char* exception.
     */
    virtual void moveItemTo(std::string itemName, AHasInventory& target);
};


class Inventory : public AHasInventory {
public:
    Inventory() {}
    virtual ~Inventory();

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

    /**
     * Returns true if the inventory contains no items.
     */
    bool isEmpty();

    friend std::ostream& operator << (std::ostream& os, Inventory& inventory);
    
private:
    Inventory(const Inventory& orig) {}
    Inventory& operator = (const Inventory& orig) {return *this;}
    
    std::map<std::string, Item&> items;
    
};

#endif	/* INVENTORY_H */

