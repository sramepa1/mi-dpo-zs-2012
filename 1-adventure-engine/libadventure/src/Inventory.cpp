/* 
 * File:   Inventory.cpp
 * Author: rusty
 * 
 * Created on 23. září 2012, 13:47
 */

#include "Inventory.h"

using namespace std;

Inventory::Inventory() {
}

Inventory::~Inventory() {
    for (multimap<string, Item&>::iterator it(items.begin()); it != items.end(); ++it) {
        delete &it->second;
    }
}

void Inventory::addItem(string name, Item& item) {
    items.insert(pair<string, Item&> (name, item));
}

void Inventory::removeItem(string name) {
    multimap<std::string, Item&>::iterator it = items.find(name);

    if(it == items.end()) {
        return;
    }

    items.erase(it);
}

Item& Inventory::findItem(string name) {
    multimap<std::string, Item&>::iterator it = items.find(name);

    if(it == items.end()) {
        throw "There is no such thing.";
    }

    return it->second;
}

void Inventory::moveItemTo(std::string name, Inventory& newInventory) {

    Item& item = findItem(name);

    if(!item.isMovable) {

        string str("You can not take ");
        str.append(name);
        str.append(".");

        throw str.c_str();
    }

    newInventory.addItem(name, item);
    removeItem(name);

}


ostream& operator << (std::ostream& os, Inventory& inventory) {

    if(inventory.items.begin() != inventory.items.end()) {

        for (multimap<string, Item&>::iterator it(inventory.items.begin()); it != inventory.items.end(); ++it) {
            os << "a "  << it->first << " " << it->second << ", ";
        }

        os << endl;
    } else {
        os << "nothing." << endl;
    }

    return os;
}
