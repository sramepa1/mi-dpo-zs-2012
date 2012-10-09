/* 
 * File:   main.cpp
 * Author: rusty
 *
 * Created on 23. září 2012, 13:17
 */

#include <cstdlib>
#include <iostream>

#include "controler.h"
#include "MyItems.h"
#include "World.h"

#include "MyCommands.h"

using namespace std;

/*
 * 
 */
int main(int argc, char** argv) {

    //TODO tupě zapoudřit všechny prvky
    //TODO zakomentovat header fily

    WorldInit myInit = {
        "Welcome to Lightning's and RH's world of (wild programming) adventure.",
        "Congratuations, your hard work and total comitment get you to hell!",
        "You are standing in a great cave.",
        "Me",
        "Programmer the mad."
    };
    
    World& world = *(new World(myInit));

    Room& r1 = world.createRoom("You are in a dark cave.");
    Room& r2 = world.createRoom("You are in a dark cave.");
    Room& r3 = world.createRoom("You are in a dark cave.");
    Room& r4 = world.createRoom("You are in a dark cave.");

    Room& startRoom = world.getStartRoom();

    startRoom.addWay(string("west"), r1);
    r1.addWay(string("east"), startRoom);
    startRoom.addWay(string("east"), r2);
    r2.addWay(string("west"), startRoom);
    startRoom.addWay(string("north"), r3);
    r3.addWay(string("south"), startRoom);
    startRoom.addWay(string("south"), r4);
    r4.addWay(string("north"), startRoom);

    startRoom.getInventory().addItem("message", *(new Item("on the wall", false)));
    r3.getInventory().addItem("torch", *(new Torch("looking very old")));

    // TODO go to hell winning condition


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

    control->addCommand("go", new MyCommandGo());
    control->addCommand("take", new MyCommandTake());
    control->addCommand("drop", new MyCommandDrop());
    control->addCommand("inventory", new MyCommandInventory());
    control->addCommand("help", new MyCommandEcho(
        "go [direction] - go to next room\n"
        "take [item]    - take an item\n"
        "drop [item]    - drop an item\n"
        "inventory      - list the inventory\n"
        "q              - quit the game"
    ));

    //control->addEvent(new Causality());

    control->run();

    //segfault
  //  delete control;
    delete &world;
    
    return 0;
}

