CFLAGS = -pedantic -Wall -Wwrite-strings -O0 -g3
INCLUDE = include

all: lib

OBJECTS = $(patsubst src/%.cpp,build/%.o,$(wildcard src/*.cpp))

build:
	mkdir build

build/%.o: src/%.cpp
	g++ $(CFLAGS) -I$(INCLUDE) -c -o $@ $<

lib: build $(OBJECTS)
	ar rcs libadventure.a $(OBJECTS)

.PHONY: clean

clean:
	rm -rf build
	rm -f libadventure.a

