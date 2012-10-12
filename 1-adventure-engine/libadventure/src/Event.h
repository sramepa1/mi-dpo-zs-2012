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

    virtual void execute() = 0;
    //TODO udělat lépe, tohle není moc pěkné
    virtual bool keepAlive() {return true;}
    
    virtual ~IEvent() {}

};

#endif	/* EVENT_H */

