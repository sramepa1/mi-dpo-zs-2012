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

#include "Character.h"
#include "Condition.h"
#include "Room.h"
#include "State.h"


class World {
public:
    World();
    ~World();

    Room& getStartRoom();
    Character& getPlayer();

    void setDescription(const char* description);
    
    Room& createRoom(const char* description);

    void addCondition(ICondition&);
    const State& evaluateGameState();

    friend std::ostream& operator << (std::ostream&, World&);

private:
    World(const World& orig) {}
    World& operator = (const World& orig) {return *this;}

    const char* description;

    Room* startRoom;
    Character* player;

    std::list<Room*> rooms;

    std::list<ICondition*> conditions;
    State* state;

};

typedef std::tr1::shared_ptr<World> worldptr;

#endif	/* WORLD_H */

