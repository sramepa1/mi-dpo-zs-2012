#ifndef STATE_H
#define STATE_H

enum GameState {
    RUNNING = 0, VICOTRY = 1, DEFEAT = 2
};

class State {
public:
    State() : state(RUNNING) {}
    State(GameState _state) : state(_state) {}

    virtual void nextState(GameState);
    virtual GameState getState();

    virtual bool isVictory() const;
    virtual bool isDefeat() const;

private:
    GameState state;

};





#endif // GAMESTATE_H
