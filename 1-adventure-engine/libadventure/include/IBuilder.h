#ifndef IBUILDER_H
#define IBUILDER_H

#include <string>
#include <tr1/memory>
#include <stdexcept>

#include "IGame.h"

/**
 * Interface for a game creator. Expects a sequence of meaningful manipulations and if they assemble a valid game,
 * allows for it to be exported in a playable wrapper.
 *
 * Methods may throw a logic_error standard exception when inconsistency is detected.
 */

class IBuilder
{
public:

    /**
     * Adds a room to the world.
     * The first room to be added this way will be the world's starting room.
     * Room's ID is a build-time unique handle, description will be displayed in-game.
     */
    virtual void addRoom(const char* roomID, const char* description) =0;

    /**
     * Adds a unidirectonal way from one existing room to another.
     * Direction is a string to the move command and will be used in-game.
     */
    virtual void addWay(const char* roomFromID, const char* roomToID, const char* direction) =0;

    /**
     * Adds an item to the world, not yet tied to any inventory.
     * Item's name must be unique an serves both as a build-time handle and as an in-game name.
     */
    virtual void addItem(const char* uniqueName, const char* description, bool isMovable) =0;

    /**
     * Adds an existing item to an existing room. An item can only be placed once.
     */
    virtual void addItemToRoom(const char* itemName, const char* roomID) =0;

    /**
     * Adds an endgame condition based on the presence of an existing item in an existing room (on the ground).
     * May specify a victory or a defeat.
     */
    virtual void addItemInRoomEnd(const char* itemName, const char* roomID, bool victorious) =0;

    /**
     * Sets the greeting line displayed when the game is started.
     */
    virtual void setGreeting(const char* worldGreeting) =0;

    /**
     * Creates a playable game instance based on previous manipulations and resets the builder.
     */
    virtual gameptr exportGame() =0;

    virtual ~IBuilder() { }
};

typedef std::tr1::shared_ptr<IBuilder> builderptr;

#endif // IBUILDER_H
