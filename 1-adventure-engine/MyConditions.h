#include "Condition.h"

#ifndef MYCONDITIONS_H
#define MYCONDITIONS_H

class MyVictoryCondition : public ICondition {
public:
    virtual bool condition(World&);
};

#endif // MYCONDITIONS_H
