/* 
 * File:   Inventory.cpp
 * Author: rusty
 * 
 * Created on 23. září 2012, 13:47
 */

#include "Inventory.h"

using namespace std;

void AHasInventory::moveItemTo(string itemName, AHasInventory& target) {
    Item& item = findItem(itemName);

    if(!item.canMove()) {

        string str("You can not take the");
        str.append(itemName);
        str.append(".");

        throw str.c_str();
    }

    target.addItem(itemName, item);
    removeItem(itemName);
}


Inventory::~Inventory() {
    for (map<string, Item&>::iterator it(items.begin()); it != items.end(); ++it) {
        delete &it->second;
    }
}

void Inventory::addItem(string name, Item& item) {
    items.insert(pair<string, Item&> (name, item));
}

void Inventory::removeItem(string name) {
    map<std::string, Item&>::iterator it = items.find(name);

    if(it == items.end()) {
        return;
    }

    items.erase(it);
}

Item& Inventory::findItem(string name) {
    map<std::string, Item&>::iterator it = items.find(name);

    if(it == items.end()) {
        throw "There is no such thing.";
    }

    return it->second;
}

Item* Inventory::matchItem(bool (*classifier)(Item &)) {
    for (map<string, Item&>::iterator it(items.begin()); it != items.end(); ++it) {
        if( (*classifier)(it->second) ) {
            return &(it->second);
        }
    }
    return NULL;
}

bool Inventory::isEmpty() {
    return items.empty();
}

ostream& operator << (std::ostream& os, Inventory& inventory) {

    if(inventory.items.empty()) {
        os << "\tnothing." << endl;

    } else {
        for (map<string, Item&>::iterator it(inventory.items.begin()); it != inventory.items.end(); ++it) {
            os << "\ta "  << it->first << " " << it->second << endl;
        }
    }
    return os;
}
