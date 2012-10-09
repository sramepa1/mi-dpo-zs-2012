/*
 * File:   World.h
 * Author: rusty
 *
 * Created on 23. září 2012, 15:39
 */

#include <list>
#include <ostream>

#include "Character.h"
#include "Condition.h"
#include "Room.h"

#ifndef WORLD_H
#define	WORLD_H


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

    void addVictoryCondition(ICondition&);
    bool testVictory();

    friend std::ostream& operator << (std::ostream&, World&);
    
    std::list<IEvent*> events;


private:
    World(const World& orig) {}
    World& operator = (const World& orig) {return *this;}

    const char* description;
    const char* vicotryMessage;

    Room* startRoom;
    Character* player;

    std::list<Room*> rooms;

    std::list<ICondition*> victoryConditions;

};

#endif	/* WORLD_H */

