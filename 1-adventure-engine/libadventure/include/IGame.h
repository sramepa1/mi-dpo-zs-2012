#ifndef IGAME_H
#define IGAME_H

#include <iostream>
#include <tr1/memory>

class IGame
{
public:
    virtual ~IGame() {}

    virtual void run(std::istream& input, std::ostream& output) =0;
};

typedef std::tr1::shared_ptr<IGame> gameptr;

#endif // IGAME_H
