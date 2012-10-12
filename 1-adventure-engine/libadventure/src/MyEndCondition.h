#ifndef MYENDCONDITION_H
#define MYENDCONDITION_H

#include "World.h"


class MyEndCondition : public ICondition
{
public:
    MyEndCondition(World* world) {}
    virtual ~MyEndCondition() {}

    virtual bool testCondition() {return true;}
};

#endif // MYENDCONDITION_H
