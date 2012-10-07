/* 
 * File:   Item.h
 * Author: rusty
 *
 * Created on 23. září 2012, 13:39
 */

#include <map>
#include <ostream>

#ifndef ITEM_H
#define	ITEM_H

class Item {
public:
    Item(const char*, bool = true);
    virtual ~Item() {}

    friend std::ostream& operator << (std::ostream&, Item&);

    bool isMovable;

private:
    Item(const Item& orig) {}
    Item& operator = (const Item& orig) {return *this;}
    
    const char* description;
    
};

#endif	/* ITEM_H */

