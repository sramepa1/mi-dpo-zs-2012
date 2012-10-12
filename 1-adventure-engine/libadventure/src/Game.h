#ifndef GAME_H
#define GAME_H

#include "IGame.h"
#include "World.h"
#include "Controller.h"

class Game : public IGame
{
public:
    Game(worldptr world);

    virtual void run(std::istream &input, std::ostream &output);

private:
    worldptr myWorld;
};

#endif // GAME_H
