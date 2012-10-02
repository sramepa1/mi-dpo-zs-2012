#include "Item.h"

#ifndef MYITEMS_H
#define MYITEMS_H

class Torch : public Item {
public:
    Torch(char*, bool, bool);
    bool isLightened;
};

#endif // MYITEMS_H
