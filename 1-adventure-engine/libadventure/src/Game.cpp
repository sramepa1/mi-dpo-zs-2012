#include "Game.h"
#include "MyCommands.h"

Game::Game(worldptr world) : myWorld(world) { }

void Game::run(std::istream &input, std::ostream &output)
{
    Controller c(input, output, myWorld);
    c.addCommand("go", new MyCommandGo());
    c.addCommand("take", new MyCommandTake());
    c.addCommand("drop", new MyCommandDrop());
    c.addCommand("inventory", new MyCommandInventory());
    c.addCommand("look", new MyCommandLook());
    c.addCommand("help", new MyCommandEcho(
        "go [direction] - go to next room\n"
        "take [item]    - take an item\n"
        "drop [item]    - drop an item\n"
        "inventory      - list the inventory\n"
        "look           - examine current room\n"
        "q              - quit the game"
    ));
    c.run();
}
