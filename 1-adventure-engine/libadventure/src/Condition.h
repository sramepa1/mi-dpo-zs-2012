/* 
 * File:   Condition.h
 * Author: rusty
 *
 * Created on 23. září 2012, 15:34
 */

#include "State.h"
#include "World.h"

#ifndef CONDITION_H
#define	CONDITION_H

class ICondition {
public:

    /**
     * Tests a condition.
     */
    virtual GameState testCondition(World& world) = 0;

    virtual ~ICondition() {}

};

#endif	/* CONDITION_H */

