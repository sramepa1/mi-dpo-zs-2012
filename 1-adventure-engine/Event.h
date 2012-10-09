/* 
 * File:   Event.h
 * Author: rusty
 *
 * Created on 23. září 2012, 15:37
 */

#ifndef EVENT_H
#define	EVENT_H

class World;

class IEvent {
public:

    virtual void execute(World&) = 0;
    
    virtual ~IEvent() {}

};

#endif	/* EVENT_H */

