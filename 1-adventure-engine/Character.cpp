/* 
 * File:   Character.cpp
 * Author: rusty
 * 
 * Created on 23. září 2012, 13:53
 */

#include "Character.h"
#include "Inventory.h"

using namespace std;

Character::Character(char* _name, char* _description, Room* _location) : name(_name),
        location(_location), description(_description) {
    
    inventory = new Inventory();
}

Character::~Character() {
    delete inventory;
}

