/* 
 * File:   Inventory.h
 * Author: rusty
 *
 * Created on 23. září 2012, 13:47
 */

#include <map>
#include <ostream>
#include <string>

#include "Item.h"

#ifndef INVENTORY_H
#define	INVENTORY_H

class Inventory {
public:
    Inventory();
    ~Inventory();

    void addItem(std::string, Item*);
    void removeItem(std::string);
    Item* findItem(std::string);
    
    friend std::ostream& operator << (std::ostream& os, Inventory&);
    
private:
    Inventory(const Inventory& orig) {}
    Inventory& operator = (const Inventory& orig) {return *this;}
    
    std::multimap<std::string, Item*> items;
    
};

#endif	/* INVENTORY_H */

