all: ps2a

ps2a: test.o LFSR.o
	g++ LFSR.o test.o -o ps2a -lsfml-graphics -lsfml-window -lsfml-system -lboost_unit_test_framework

LFSR.o: LFSR.cpp LFSR.hpp
	g++ -c LFSR.cpp -Wall -Werror -ansi -pedantic

test.o: test.cpp LFSR.hpp
	g++ -c test.cpp -Wall -Werror -ansi -pedantic

clean:
	rm -rf ps2a *.o *.~
