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

    /**
     * Get the room where is the player at the start of the game.
     */
    Room& getStartRoom();

    /**
     * Get the player's character.
     */
    Character& getPlayer();

    /**
     * Get the room where is the player currently located.
     */
    Room& getCurrentRoom();

    /**
     * Set the world's description-
     */
    void setDescription(const char* description);
    
    /**
     * Create a room in this world. This is a factory method.
     */
    Room& createRoom(const char* description, bool isDark);

    /**
     * Add a condition which modifies the state of the game.
     */
    void addCondition(ICondition&);

    /**
     * Determine the current gamestate from a given conditions.
     */
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

