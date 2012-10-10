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
        // TODO name parameters in headers!
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

