#include "Item.h"

#ifndef MYITEMS_H
#define MYITEMS_H

class Torch : public Item {
public:
    Torch(const char*, bool, bool);
    bool isLightened;
};

#endif // MYITEMS_H
