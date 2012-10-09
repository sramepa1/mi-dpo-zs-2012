/* 
 * File:   Condition.h
 * Author: rusty
 *
 * Created on 23. září 2012, 15:34
 */

#include "World.h"

#ifndef CONDITION_H
#define	CONDITION_H

class ICondition {
public:

    virtual bool condition(World&) = 0;

    virtual ~ICondition() {}

};

class VictoryCondition : public ICondition {
public:
    
    virtual bool condition(World&) = 0;

    
    virtual ~ICondition() {}

};

#endif	/* CONDITION_H */

