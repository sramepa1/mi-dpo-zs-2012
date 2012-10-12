/*
 * File:   World.h
 * Author: rusty
 *
 * Created on 23. září 2012, 15:39
 */
#ifndef WORLD_H
#define	WORLD_H

#include <list>
#include <ostream>

#include "Character.h"
#include "Condition.h"
#include "Room.h"
#include "State.h"


struct WorldInit{
    const char* worldDescription;
    const char* vicotryMessage;
    const char* startRoomDescription;
    const char* playerName;
    const char* playerDescription;
};


class World {
public:
    World(const WorldInit&);
    ~World();

    Room& getStartRoom();
    Character& getPlayer();
    
    Room& createRoom(const char* description);

    void addCondition(ICondition&);
    const State& evaluateGameState();

    friend std::ostream& operator << (std::ostream&, World&);
    
   // std::list<IEvent*> events;


private:
    World(const World& orig) {}
    World& operator = (const World& orig) {return *this;}

    const char* description;
    const char* vicotryMessage;

    Room* startRoom;
    Character* player;

    std::list<Room*> rooms;

    std::list<ICondition*> conditions;
    State* state;

};

#endif	/* WORLD_H */

