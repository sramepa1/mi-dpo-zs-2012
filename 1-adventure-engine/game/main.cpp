/* 
 * File:   main.cpp
 * Author: rusty
 *
 * Created on 23. září 2012, 13:17
 */

#include <iostream>
#include "AdventureEngine.h"

using namespace std;

int main() {

    //TODO tupě zapoudřit všechny prvky
    //TODO zakomentovat header fily

    try {

        BuilderFactory bf;
        builderptr builder = bf.createBuilder();

        builder->setGreeting("Welcome to Lightning's and RH's world of (wild programming) adventure.");
        builder->setPlayer("Me","Programmer, the mad.");

        builder->addRoom("Start", "You are in a dark cave.");
        builder->addRoom("WestCave", "You are in a dark cave.");
        builder->addRoom("EastCave", "You are in a dark cave.");
        builder->addRoom("SouthCave", "You are in a dark cave.");
        builder->addRoom("NorthCave", "You are in a dark cave.");

        builder->addWay("Start", "WestCave", "west");
        builder->addWay("WestCave", "Start", "east");
        builder->addWay("Start", "EastCave", "east");
        builder->addWay("EastCave", "Start", "west");
        builder->addWay("Start", "NorthCave", "north");
        builder->addWay("NorthCave", "Start", "south");
        builder->addWay("Start", "SouthCave", "south");
        builder->addWay("SouthCave", "Start", "north");

        builder->addItemToRoom("Start", "message", "on the wall", false);
        builder->addItemToRoom("WestCave", "bone", "- likely human", true);

        // TODO victory condition
        // TODO special items // r3.getInventory().addItem("torch", *(new Torch("looking very old")));

        gameptr game = builder->exportGame();
        game->run(cin, cout);

    } catch(logic_error e) {
        // This exception signals misuse of the API. Consider this an assertion that execution should never get here.
        cerr << "ASSERTION FAILED - something went wrong during building: " << endl << e.what() << endl;
        return 1;
    }

    return 0;
}

