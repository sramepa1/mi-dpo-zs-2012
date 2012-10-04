/* 
 * File:   World.h
 * Author: rusty
 *
 * Created on 23. září 2012, 15:39
 */

#include <list>
#include <ostream>

#include "Causality.h"
#include "Character.h"
#include "Room.h"

#ifndef WORLD_H
#define	WORLD_H


struct WorldInit{
    const char* worldDescription;
    const char* startRoomDescription;
    const char* playerName;
    const char* playerDescription;
};


class World {
public:
    World(const WorldInit&);

    ~World();

    Character* player;
    ICondition* victoryCond;

    Room* startRoom;
    
    Room& createRoom(const char* description);

    friend std::ostream& operator << (std::ostream&, World&);
    
private:
    World(const World& orig) {}
    World& operator = (const World& orig) {return *this;}

    const char* description;


    std::list<Room*> rooms;
};

#endif	/* WORLD_H */

