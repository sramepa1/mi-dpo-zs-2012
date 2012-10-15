all: adventure
	@echo "\n\n------------------------------------------"
	@echo "To run the game and play, type 'make run'"
	@echo "To run automatically, type 'make autoplay'"
	@echo "------------------------------------------\n\n\n"


adventure: game/game
	cp game/game adventure

game/game: libadventure/libadventure.a
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

autoplay: adventure autoplay.txt
	./adventure < autoplay.txt
