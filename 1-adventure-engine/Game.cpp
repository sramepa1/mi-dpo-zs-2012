#include "Game.h"

Game::Game(worldptr world) : myWorld(world) { }

void Game::run(std::istream &input, std::ostream &output)
{
    Controller c(input, output, myWorld);
    c.run();
}
