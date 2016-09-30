all: ps2b

ps2b: PhotoMagic.o LFSR.o
	g++ LFSR.o PhotoMagic.o -o ps2b -lsfml-graphics -lsfml-window -lsfml-system

LFSR.o: LFSR.cpp LFSR.hpp
	g++ -c LFSR.cpp -Wall -Werror -ansi -pedantic

test.o: PhotoMagic.cpp PhotoMagic.hpp
	g++ -c PhotoMagic.cpp -Wall -Werror -ansi -pedantic

clean:
	rm -rf ps2b *.o *.~
