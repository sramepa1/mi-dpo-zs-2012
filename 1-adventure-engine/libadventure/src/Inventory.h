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

class Inventory {
public:
    Inventory();
    ~Inventory();

    /**
     * Add an item to the inventory.
     */
    void addItem(std::string itemName, Item& item);

    /**
     * Remove an item from the inventory.
     */
    void removeItem(std::string itemName);

    /**
     * Find an item in the inventory. If not found then method throws an const char* exception.
     */
    Item& findItem(std::string itemName);

    /**
     * Move an item to another inventory. If not found then method throws a const char* exception.
     */
    void moveItemTo(std::string itemName, Inventory& inventory);

    friend std::ostream& operator << (std::ostream& os, Inventory& inventory);
    
private:
    Inventory(const Inventory& orig) {}
    Inventory& operator = (const Inventory& orig) {return *this;}
    
    std::map<std::string, Item&> items;
    
};

#endif	/* INVENTORY_H */

