#include "State.h"

#include <map>
using namespace std;

static GameState TransitionLookup[][3]  = {
    // RUNNING = 0, VICOTRY = 1, DEFEAT = 2
    {RUNNING, VICOTRY, DEFEAT},
    {VICOTRY, VICOTRY, VICOTRY},
    {DEFEAT, VICOTRY, DEFEAT},
};

void State::nextState(GameState nextState) {
    state = TransitionLookup[state][nextState];
}

GameState State::getState() {
    return state;
}

bool State::isVictory() const {
    return state == VICOTRY;
}

bool State::isDefeat() const {
    return state == DEFEAT;
}
