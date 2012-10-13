/* 
 * File:   Item.h
 * Author: rusty
 *
 * Created on 23. září 2012, 13:39
 */
#ifndef ITEM_H
#define	ITEM_H

#include <map>
#include <ostream>


class Item {
public:
    Item(const char* description, bool isMovable= true);
    virtual ~Item() {}

    /**
     * Can the item be moved?
     */
    bool canMove();

    friend std::ostream& operator << (std::ostream& os, Item& item);

private:
    Item(const Item& orig) {}
    Item& operator = (const Item& orig) {return *this;}
    
    bool isMovable;
    const char* description;
    
};

#endif	/* ITEM_H */

