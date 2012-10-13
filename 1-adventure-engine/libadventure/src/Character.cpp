/* 
 * File:   Character.cpp
 * Author: rusty
 * 
 * Created on 23. září 2012, 13:53
 */

#include "Character.h"
#include "Inventory.h"

using namespace std;

Character::Character(const char* _name, const char* _description, Room& _location) : name(_name), description(_description),
        location(&_location) {
    
    inventory = new Inventory();
}

Character::~Character() {
    delete inventory;
}

void Character::goTo(string direction) {
    teleport(location->findWay(direction));
}

void Character::teleport(Room &room) {
    location = &(room);
}

Room& Character::getLocation() {
    return *location;
}

void Character::takeItem(string itemName) {
    location->getInventory().moveItemTo(itemName, *inventory);
}

void Character::dropItem(string itemName) {
    inventory->moveItemTo(itemName, location->getInventory());
}

void Character::listItems(ostream& os) {
    os << "You have " << (*inventory);
}

ostream& operator << (std::ostream& os, Character& room) {
    os << room << endl;

    return os;
}
