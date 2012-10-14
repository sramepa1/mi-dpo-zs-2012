#ifndef CONTROLLER_H
#define CONTROLLER_H

#include <istream>
#include <list>
#include <map>
#include <ostream>
#include <string>
#include <sstream>

#include "Command.h"
#include "World.h"


class Controller {
public:
    Controller(std::istream& is, std::ostream& os, worldptr worldPointer);
    ~Controller();

    /**
     * Add a command to the controller.
     */
    void addCommand(std::string, ICommand*);

    /**
     * Starts the game. This method is blocking until the game ends.
     */
    void run();

private:

    std::string prompt(std::string prompt);
    bool continueGame(std::map<std::string, ICommand*>::iterator it, std::istringstream& commandStream);

    std::istream& is;
    std::ostream& os;

    std::map<std::string, ICommand*> commands;
    worldptr world;

};

#endif // CONTROLLER_H
