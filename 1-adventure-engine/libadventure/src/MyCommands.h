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
    MyCommandLight() {}
    virtual ~MyCommandLight() {}

    virtual void commandExecute(std::istringstream&, std::ostream&, World&);

private:
    Character* player;
};

class MyCommandLook : public ACommand {
public:
    MyCommandLook() {}
    virtual ~MyCommandLook() {}

    virtual void commandExecute(std::istringstream&, std::ostream&, World&);
};


#endif // MYCOMMANDS_H
