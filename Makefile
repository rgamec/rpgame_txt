rpgame: rpgame.cpp enemies.cpp
	g++ -Wall -o bin/rpgame enemies.cpp rpgame.cpp -I.

clean:
	rm -f bin/rpgame
