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
        lightSource(NULL), location(&_location) {
    
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

bool Character::toggleLight() {
    if(lightSource == NULL) {
        throw "You don't have a light source.";
    } else {
        bool newLight = !lightSource->isLightened;
        lightSource->isLightened = newLight;
        return newLight;
    }
}

bool torchHelper(Item& item) {
    return dynamic_cast<Torch*>(&item) != NULL;
}

void Character::checkForLightSource(Item &item, bool incoming) {
    if(dynamic_cast<Torch*>(&item) == NULL) {
        return; // not a torch
    }
    if(incoming && lightSource == NULL) {
        lightSource = (Torch*)&item;
        return;
    }
    if(!incoming && lightSource == &item) {
        lightSource = (Torch*)inventory->matchItem(&torchHelper);
        ((Torch&)item).isLightened = false;  // light goes off when dropped
    }
}

bool Character::emitsLight() {
    return lightSource != NULL && lightSource->isLightened;
}

void Character::requireLight() {
    if(!location->isIlluminated(*this)) {
        throw "You can't do that when you can't see anything.";
    }
}

void Character::takeItem(string itemName) {
    requireLight();
    location->moveItemTo(itemName, *inventory);
    checkForLightSource(inventory->findItem(itemName),true);
}

void Character::dropItem(string itemName) {
    requireLight();
    inventory->moveItemTo(itemName, *location);
    checkForLightSource(location->findItem(itemName),false);
}

void Character::listItems(ostream& os) {
    requireLight();
    os << "You have: " << endl << (*inventory);
}

void Character::addItem(string itemName, Item& item) {
    checkForLightSource(item,true);
    inventory->addItem(itemName, item);
}

void Character::removeItem(string itemName) {
    Item& item = inventory->findItem(itemName);
    inventory->removeItem(itemName);
    checkForLightSource(item,false);
}

Item& Character::findItem(string itemName) {
    return inventory->findItem(itemName);
}

ostream& operator << (std::ostream& os, Character& character) {
    if(character.location->isIlluminated(character)) {
        os << *(character.location);
    } else {
        os << "You are in a dark place. It is pitch black. You can't see anything." << endl;
    }
    return os;
}
