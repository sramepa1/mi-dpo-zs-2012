#ifndef STATE_H
#define STATE_H

enum GameState {
    RUNNING = 0, VICTORY = 1, DEFEAT = 2
};

class State {
public:
    State();
    State(GameState _state) : state(_state) {}

    virtual void nextState(GameState);
    virtual GameState getState();

    virtual bool isVictory() const;
    virtual bool isDefeat() const;

private:
    GameState state;

};





#endif // GAMESTATE_H
