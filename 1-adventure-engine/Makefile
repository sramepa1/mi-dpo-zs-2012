all: adventure

adventure:	game/game
	cp game/game adventure

game/game:	libadventure/libadventure.a
	cd game && $(MAKE) all

libadventure/libadventure.a:
	cd libadventure && $(MAKE) all

.PHONY: clean

clean:
	cd game && $(MAKE) clean
	cd libadventure && $(MAKE) clean
	rm -f adventure

run: adventure
	./adventure

