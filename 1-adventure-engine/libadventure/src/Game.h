#ifndef GAME_H
#define GAME_H

#include "IGame.h"
#include "World.h"
#include "Controller.h"

class Game : public IGame
{
public:
    /**
     * Creates a new game, wrapping the supplied world
     */
    Game(worldptr world);
    virtual ~Game() {}

    /**
     * Runs the game using a default controller with the supplied streams.
     */
    virtual void run(std::istream &input, std::ostream &output);

private:
    worldptr myWorld;
};

#endif // GAME_H
