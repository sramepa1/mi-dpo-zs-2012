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
#include <tr1/memory>

#include "Causality.h"
#include "Character.h"
#include "Room.h"


class World {
public:
    World();
    ~World();

    ICondition* victoryCond;

    Room& getStartRoom();
    Character& getPlayer();

    void setDescription(const char* description);
    void setPlayer(const char* playerName, const char* playerDesc);
    
    Room& createRoom(const char* description);

    friend std::ostream& operator << (std::ostream&, World&);
    
private:
    World(const World& orig) {}
    World& operator = (const World& orig) {return *this;}

    const char* description;
    Room* startRoom;
    Character* player;

    std::list<Room*> rooms;
};

typedef std::tr1::shared_ptr<World> worldptr;

#endif	/* WORLD_H */

