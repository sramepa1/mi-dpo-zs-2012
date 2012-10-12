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

    void addItem(std::string, Item&);
    void removeItem(std::string);
    Item& findItem(std::string);

    void moveItemTo(std::string, Inventory&);

    friend std::ostream& operator << (std::ostream& os, Inventory&);
    
private:
    Inventory(const Inventory& orig) {}
    Inventory& operator = (const Inventory& orig) {return *this;}
    
    std::multimap<std::string, Item&> items;
    
};

#endif	/* INVENTORY_H */

