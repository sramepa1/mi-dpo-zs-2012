#ifndef IGAME_H
#define IGAME_H

#include <iostream>
#include <tr1/memory>

/**
 * Interface for a wrapper of a playable game structure.
 */

class IGame
{
public:
    virtual ~IGame() {}

    /**
     * Runs this game instance on the supplied input and output streams.
     */
    virtual void run(std::istream& input, std::ostream& output) =0;
};

typedef std::tr1::shared_ptr<IGame> gameptr;

#endif // IGAME_H
