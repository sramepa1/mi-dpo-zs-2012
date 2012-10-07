
#include "Command.h"
#include "World.h"

#ifndef MYCOMMANDS_H
#define MYCOMMANDS_H

class MyCommandGo : public ICommand {
public:
    MyCommandGo() {}
    virtual ~MyCommandGo() {}

    virtual void execute(std::istringstream&, std::ostream&, World&);
};

class MyCommandTake : public ICommand {
public:
    MyCommandTake() {}
    virtual ~MyCommandTake() {}

    virtual void execute(std::istringstream&, std::ostream&, World&);
};

class MyCommandDrop : public ICommand {
public:
    MyCommandDrop() {}
    virtual ~MyCommandDrop() {}

    virtual void execute(std::istringstream&, std::ostream&, World&);
};

class MyCommandInventory : public ICommand {
public:
    MyCommandInventory() {}
    virtual ~MyCommandInventory() {}

    virtual void execute(std::istringstream&, std::ostream&, World&);
};

class MyCommandEcho : public ICommand {
public:
    MyCommandEcho(const char* _echo) : echo(_echo) {}
    virtual ~MyCommandEcho() {}

    virtual void execute(std::istringstream&, std::ostream&, World&);

private:
    const char* echo;
};

class MyCommandLight : public ICommand {
public:
    MyCommandLight(Character* _player) : player(_player) {}
    virtual ~MyCommandLight() {}

    virtual void execute(std::istringstream&, std::ostream&, World&);

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
