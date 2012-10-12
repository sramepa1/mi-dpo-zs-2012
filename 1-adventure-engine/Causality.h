/* 
 * File:   Causality.h
 * Author: rusty
 *
 * Created on 23. září 2012, 15:40
 */
#ifndef CAUSALITY_H
#define	CAUSALITY_H

/*
#include "Condition.h"
#include "Event.h"


class Causality : public IEvent {
public:
    Causality(ICondition*, IEvent*);
    virtual ~Causality();
    
    virtual void execute();
    virtual bool keepAlive();
    
private:
    Causality(const Causality& orig) {}
    Causality& operator = (const Causality& orig) {return *this;}
    
    ICondition* condition;
    IEvent* event;

    bool flag;
};

#endif	/* CAUSALITY_H */

