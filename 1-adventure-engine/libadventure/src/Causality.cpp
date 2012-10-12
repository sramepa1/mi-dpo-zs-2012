/* 
 * File:   Causality.cpp
 * Author: rusty
 * 
 * Created on 23. září 2012, 15:40
 */

#include "Causality.h"

Causality::Causality(ICondition* _con, IEvent* _eve) : condition(_con), event(_eve) {
    flag = false;
}

Causality::~Causality() {
    delete condition;
    delete event;
}

void Causality::execute() {
    if(condition->testCondition()) {
        event->execute();
        flag = true;
    }
}

bool Causality::keepAlive() {
    if(flag) {
        return event->keepAlive();
    }

    return true;
}
