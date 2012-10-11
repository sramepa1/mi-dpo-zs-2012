CFLAGS = -pedantic -Wall -Wwrite-strings -O0 -g3

all: game

OBJECTS = $(patsubst %.cpp,build/%.o,$(wildcard ./*.cpp))

build:
	mkdir build

build/%.o: %.cpp
	g++ $(CFLAGS) -c -o $@ $<

game: build $(OBJECTS)
	g++ -o $@ $(OBJECTS)

.PHONY: clean

clean:
	rm -rf build
	rm -f game

run:
	@echo "Vypsat nápovědu"



