/* 
 * File:   main.cpp
 * Author: rusty
 *
 * Created on 23. září 2012, 13:17
 */

#include <cstdlib>
#include <iostream>

#include "controler.h"
#include "World.h"

#include "MyCommands.h"

using namespace std;

/*
 * 
 */
int main(int argc, char** argv) {

    //TODO uděla factory na místnosti (auto registrace do světa)
    //TODO tupě zapoudřit všechny prvky
    //TODO vazby mezi místnostmi aby to neporušilo demeter ale ani neubralo na obecnosti ... přez stringy ?
    //TODO zakomentovat header fily

    WorldInit myInit = {
        "Welcome to Lightning's and RH's world of (wild programming) adventure.",
        "You are standing in a great cave.",
        "Me",
        "Programmer the mad."
    };
    
    World& world = *(new World(myInit));

    Room& r1 = world.createRoom("You are in a dark cave.");

    Room& startRoom = *(world.startRoom);

    startRoom.addWay(string("west"), r1);
    r1.addWay(string("east"), startRoom);


/*
    world->startRoom->north = world->registerRoom(new Room("You are in a dark cave. The only way leads south."));
    world->startRoom->west = world->registerRoom(new Room("You are in a dark cave. The only way leads east."));
    world->startRoom->east = world->registerRoom(new Room("You are in a dark cave. The only way leads west."));
    world->startRoom->south = world->registerRoom(new Room("You are in a dark cave. The only way leads north."));

    world->startRoom->north->south = world->startRoom;
    world->startRoom->south->north = world->startRoom;
    world->startRoom->west->east = world->startRoom;
    world->startRoom->east->west = world->startRoom;
*/

  //  world->startRoom->inventory->addItem("message", new Item("on the wall", false));
   // world->startRoom->east->inventory->addItem("torch", new Item("looking very old"));

    Controler* control = new Controler(cin, cout, world);

    control->addCommand("go", new MyCommandGo(world.player));
    control->addCommand("take", new MyCommandTake(world.player));
    control->addCommand("drop", new MyCommandDrop(world.player));
    control->addCommand("inventory", new MyCommandInventory(world.player));

    //control->addEvent(new Causality());

    control->run();

    //segfault
  //  delete control;
    delete &world;
    
    return 0;
}

