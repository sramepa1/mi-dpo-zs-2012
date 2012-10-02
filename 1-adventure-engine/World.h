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

class World {
public:
    World(Character* _player = NULL, ICondition* _victory = NULL, char* _description = NULL, Room* _startRoom = NULL)
            : player(_player), victoryCond(_victory), startRoom(_startRoom), description(_description) {}
    ~World();

    Character* player;
    ICondition* victoryCond;
    Room* startRoom;
    char* description;
    
    Room* registerRoom(Room*);

    friend std::ostream& operator << (std::ostream&, World&);
    
private:
    World(const World& orig) {}
    World& operator = (const World& orig) {return *this;}

    std::list<Room*> rooms;
};

#endif	/* WORLD_H */

