// this will be main.cpp when we move to a library

#include <iostream>

#include "AdventureEngine.h"

using namespace std;

int futuremain() {

    BuilderFactory bf;
    builderptr builder = bf.createBuilder();

    builder->setGreeting("Welcome to Lightning's and RH's world of (wild programming) adventure.");
    builder->setPlayer("Me","Programmer, the mad.");

    builder->addRoom("Start", "You are in a dark cave.");


    gameptr game = builder->exportGame();

    game->run(cin, cout);

    return 0;
}
