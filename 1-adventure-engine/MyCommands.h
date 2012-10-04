
#include "Command.h"
#include "World.h"

#ifndef MYCOMMANDS_H
#define MYCOMMANDS_H

class MyCommandGo : public ICommand {
public:
    MyCommandGo(Character* _player) : player(_player) {}
    virtual ~MyCommandGo() {}

    virtual void execute(std::istringstream&, std::ostream&);

private:
    Character* player;
};

class MyCommandTake : public ICommand {
public:
    MyCommandTake(Character* _player) : player(_player) {}
    virtual ~MyCommandTake() {}

    virtual void execute(std::istringstream&, std::ostream&);

private:
    Character* player;
};

class MyCommandDrop : public ICommand {
public:
    MyCommandDrop(Character* _player) : player(_player) {}
    virtual ~MyCommandDrop() {}

    virtual void execute(std::istringstream&, std::ostream&);

private:
    Character* player;
};

class MyCommandInventory : public ICommand {
public:
    MyCommandInventory(Character* _player) : player(_player) {}
    virtual ~MyCommandInventory() {}

    virtual void execute(std::istringstream&, std::ostream&);

private:
    Character* player;
};

class MyCommandEcho : public ICommand {
public:
    MyCommandEcho(const char* _echo) : echo(_echo) {}
    virtual ~MyCommandEcho() {}

    virtual void execute(std::istringstream&, std::ostream&);

private:
    const char* echo;
};

class MyCommandLight : public ICommand {
public:
    MyCommandLight(Character* _player) : player(_player) {}
    virtual ~MyCommandLight() {}

    virtual void execute(std::istringstream&, std::ostream&);

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
