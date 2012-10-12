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
    Item(const char*, bool = true);
    virtual ~Item() {}

    bool canMove();

    friend std::ostream& operator << (std::ostream&, Item&);

private:
    Item(const Item& orig) {}
    Item& operator = (const Item& orig) {return *this;}
    
    const char* description;
    bool isMovable;
    
};

#endif	/* ITEM_H */

