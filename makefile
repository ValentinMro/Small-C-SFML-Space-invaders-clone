FSMLFLAGS = -lsfml-graphics -lsfml-window -lsfml-system

# Rule 1: Link executable and execute game
obj/executable: obj/main.o obj/window.o obj/game.o obj/playerInputs.o obj/gameStats.o obj/gameSounds.o
	g++ -std=c++2a -o obj/executable obj/main.o  obj/window.o obj/game.o obj/playerInputs.o obj/gameStats.o obj/gameSounds.o $(FSMLFLAGS)

# Rule 2: Compile main.cpp
obj/main.o: src/main.cpp
	g++ -std=c++2a -o obj/main.o -c src/main.cpp 

#Rule 3: Compile game.cpp
obj/game.o: src/window.cpp src/playerInputs.cpp src/gameStats.cpp src/gameSounds.cpp
	g++ -std=c++2a -o obj/game.o -c src/game.cpp

#Rule 4: Compile window.cpp
obj/window.o: src/window.cpp
	g++ -std=c++2a -o obj/window.o -c src/window.cpp

#Rule 5: Compile playerInputs.cpp
obj/playerInputs.o: src/playerInputs.cpp
	g++ -std=c++2a -o obj/playerInputs.o -c src/playerInputs.cpp

#Rule 6: Compile gameStats.cpp
obj/gameStats.o: src/gameStats.cpp
	g++ -std=c++2a -o obj/gameStats.o -c src/gameStats.cpp

#Rule 6: Compile gameSounds.cpp
obj/gameSounds.o: src/gameSounds.cpp
	g++ -std=c++2a -o obj/gameSounds.o -c src/gameSounds.cpp	

# Delete all binaries
clean:
	rm -f obj/*