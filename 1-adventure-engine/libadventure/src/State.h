#ifndef STATE_H
#define STATE_H

enum GameState {
    RUNNING = 0, VICTORY = 1, DEFEAT = 2
};

class State {
public:
    State() : state(RUNNING) {}
    State(GameState _state) : state(_state) {}

    /**
     * Determine next state of the game.
     */
    virtual void nextState(GameState state);

    /**
     * Get current state of the game.
     */
    virtual GameState getState();

    /**
     * Is the game in victory state?
     */
    virtual bool isVictory() const;

    /**
     * Is the game in defeat state?.
     */
    virtual bool isDefeat() const;

private:
    GameState state;

};





#endif // GAMESTATE_H
