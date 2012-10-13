CFLAGS = -pedantic -Wall -Wwrite-strings -O0 -g3
LDFLAGS = -static
INCLUDE = ../libadventure/include
LIBPATH = ../libadventure

all: game

OBJECTS = $(patsubst %.cpp,build/%.o,$(wildcard *.cpp))

build:
	mkdir build

build/%.o: %.cpp
	g++ $(CFLAGS) -I$(INCLUDE) -c -o $@ $<

game: build $(OBJECTS)
	g++ $(LDFLAGS) -L$(LIBPATH) -o $@ $(OBJECTS) -ladventure

.PHONY: clean

clean:
	rm -rf build
	rm -f game

run: game
	./game

