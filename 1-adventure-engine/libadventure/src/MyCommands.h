#ifndef MYCOMMANDS_H
#define MYCOMMANDS_H

#include "Command.h"
#include "World.h"


class MyCommandGo : public ACommand {
public:
    MyCommandGo() {}
    virtual ~MyCommandGo() {}

    virtual void commandExecute(std::istringstream&, std::ostream&, World&);
};

class MyCommandTake : public ACommand {
public:
    MyCommandTake() {}
    virtual ~MyCommandTake() {}

    virtual void commandExecute(std::istringstream&, std::ostream&, World&);
};

class MyCommandDrop : public ACommand {
public:
    MyCommandDrop() {}
    virtual ~MyCommandDrop() {}

    virtual void commandExecute(std::istringstream&, std::ostream&, World&);
};

class MyCommandInventory : public ACommand {
public:
    MyCommandInventory() {}
    virtual ~MyCommandInventory() {}

    virtual void commandExecute(std::istringstream&, std::ostream&, World&);
};

class MyCommandEcho : public ACommand {
public:
    MyCommandEcho(const char* _echo) : echo(_echo) {}
    virtual ~MyCommandEcho() {}

    virtual void commandExecute(std::istringstream&, std::ostream&, World&);

private:
    const char* echo;
};

class MyCommandLight : public ACommand {
public:
    MyCommandLight(Character* _player) : player(_player) {}
    virtual ~MyCommandLight() {}

    virtual void commandExecute(std::istringstream&, std::ostream&, World&);

private:
    Character* player;
};

/*
class MyCommandSouth : public ICommand {
public:
    virtual ~MyCommandSouth() {}

    virtual void execute(std::istringstream&, std::ostream&);
};

class MyCommandWest : public ICommand {
public:
    virtual ~MyCommandWest() {}

    virtual void execute(std::istringstream&, std::ostream&);
};

class MyCommandEast : public ICommand {
public:
    virtual ~MyCommandEast() {}

    virtual void execute(std::istringstream&, std::ostream&);
};
*/

#endif // MYCOMMANDS_H
