#ifndef MYITEMS_H
#define MYITEMS_H

#include "Item.h"


class Torch : public Item {
public:
    Torch(const char*,bool _isMovable = true, bool _isLightened = true);
    bool isLightened;
};

#endif // MYITEMS_H
