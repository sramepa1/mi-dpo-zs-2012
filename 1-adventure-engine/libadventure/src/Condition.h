/* 
 * File:   Condition.h
 * Author: rusty
 *
 * Created on 23. září 2012, 15:34
 */

#ifndef CONDITION_H
#define	CONDITION_H

class ICondition {
public:
    
    virtual bool testCondition() = 0;
    
    virtual ~ICondition() {}

};

#endif	/* CONDITION_H */

