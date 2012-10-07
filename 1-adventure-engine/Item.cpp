/* 
 * File:   Item.cpp
 * Author: rusty
 * 
 * Created on 23. září 2012, 13:39
 */

#include "Item.h"

using namespace std;

Item::Item(const char* _description, bool _isMovable) : isMovable(_isMovable), description(_description) {}

ostream& operator << (std::ostream& os, Item& item) {
    os << item.description;
    return os;
}
