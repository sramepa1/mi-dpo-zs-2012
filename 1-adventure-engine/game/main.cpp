#include <iostream>
#include "AdventureEngine.h"

using namespace std;

/**
 * A demo program using our adventure engine library.
 * Only includes builder-related headers and uses them to make and run a game.
 * The world is a limited remake of the beginning of ZORK I.
 */

int main() {

    // TODO Lantern, light/dark.

    try {
        BuilderFactory bf;
        builderptr builder = bf.createBuilder();

        builder->setGreeting("BORK: The Very Small Underground Empire");

        builder->addRoom("Start","You are standing in an open field west of a white house.");
        builder->addRoom("NHouse","You are facing the north side of a white house.");
        builder->addRoom("SHouse","You are facing the south side of a white house.");
        builder->addRoom("BehindHouse","You are behind the white house. There is an open window in one corner.");
        builder->addRoom("Kitchen","You are in the kitchen of the white house. A dark staircase can be seen leading upward.");
        builder->addRoom("LRoom","You are in the living room. A rug lies beside an open trap door.");
        builder->addRoom("Attic","This is the attic. The only exit is a stairway leading down.");
        builder->addRoom("Cellar","You are in a dark and damp cellar. You feel that you need to put some rope on the ground to move on.");

        builder->addWay("Start","NHouse","north");
        builder->addWay("Start","SHouse","south");
        builder->addWay("SHouse","Start","west");
        builder->addWay("NHouse","Start","west");
        builder->addWay("SHouse","BehindHouse","east");
        builder->addWay("NHouse","BehindHouse","east");
        builder->addWay("BehindHouse","SHouse","south");
        builder->addWay("BehindHouse","NHouse","north");
        builder->addWay("BehindHouse","Kitchen","west");
        builder->addWay("Kitchen","Attic","up");
        builder->addWay("Kitchen","LRoom","west");
        builder->addWay("Kitchen","BehindHouse","east");
        builder->addWay("Attic","Kitchen","down");
        builder->addWay("LRoom","Kitchen","east");
        builder->addWay("LRoom","Cellar","down");
        builder->addWay("Cellar","LRoom","up");

        builder->addItem("mailbox","that cannot be opened",false);
        builder->addItem("table","recently used for preparation of food",false);
        builder->addItem("lantern","with fresh batteries",true);
        builder->addItem("sword","of great antiquity",true);
        builder->addItem("cupboard","- likely a trophy case",false);
        builder->addItem("rope","- a large coil of it",true);
        builder->addItem("knife","looking pretty nasty",true);
        builder->addItem("bottle","of water",true);

        builder->addItemToRoom("mailbox","Start");
        builder->addItemToRoom("table","Kitchen");
        builder->addItemToRoom("lantern","LRoom");
        builder->addItemToRoom("sword","LRoom");
        builder->addItemToRoom("cupboard","LRoom");
        builder->addItemToRoom("rope","Attic");
        builder->addItemToRoom("knife","Attic");
        builder->addItemToRoom("bottle","Kitchen");

        builder->addItemInRoomEnd("rope","Cellar",true);

        gameptr game = builder->exportGame();
        game->run(cin, cout);

    } catch(logic_error e) {
        // This exception signals misuse of the API. Consider this an assertion that execution should never get here.
        cerr << "ASSERTION FAILED - something went wrong during building: " << endl << e.what() << endl;
        return 1;
    }

    return 0;
}

