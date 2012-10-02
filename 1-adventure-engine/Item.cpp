/* 
 * File:   Item.cpp
 * Author: rusty
 * 
 * Created on 23. září 2012, 13:39
 */

#include "Item.h"

using namespace std;

Item::Item(char* _description, bool _isMovable) : description(_description), isMovable(_isMovable) {}

ostream& operator << (std::ostream& os, Item& item) {
    os << item.description;
    return os;
}
