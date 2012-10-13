#include "State.h"

#include <map>
using namespace std;

static GameState TransitionLookup[][3]  = {
    // RUNNING = 0, VICOTRY = 1, DEFEAT = 2
    {RUNNING, VICTORY, DEFEAT},
    {VICTORY, VICTORY, VICTORY},
    {DEFEAT, VICTORY, DEFEAT},
};

State::State() {
    state = RUNNING;
}

void State::nextState(GameState nextState) {
    state = TransitionLookup[state][nextState];
}

GameState State::getState() {
    return state;
}

bool State::isVictory() const {
    return state == VICTORY;
}

bool State::isDefeat() const {
    return state == DEFEAT;
}
