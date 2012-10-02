
#include "World.h"

#ifndef MYENDCONDITION_H
#define MYENDCONDITION_H

class MyEndCondition : public ICondition
{
public:
    MyEndCondition(World* world) {}
    virtual ~MyEndCondition() {}

    virtual bool testCondition() {return true;}
};

#endif // MYENDCONDITION_H
