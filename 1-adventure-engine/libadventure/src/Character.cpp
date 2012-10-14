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
    location->moveItemTo(itemName, *inventory);
}

void Character::dropItem(string itemName) {
    inventory->moveItemTo(itemName, *location);
}

void Character::listItems(ostream& os) {
    os << "You have: " << endl << (*inventory);
}

void Character::addItem(string itemName, Item& item) {
    inventory->addItem(itemName, item);
}

void Character::removeItem(string itemName) {
    inventory->removeItem(itemName);
}

Item& Character::findItem(string itemName) {
    return inventory->findItem(itemName);
}

ostream& operator << (std::ostream& os, Character& character) {
    os << *(character.location);

    return os;
}
