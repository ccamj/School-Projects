all: ps3a

ps3a: main.o Body.o
	g++ Body.o main.o -o NBody -lsfml-graphics -lsfml-window -lsfml-system

Body.o: Body.cpp Body.hpp
	g++ -c Body.cpp -Wall -Werror -ansi -pedantic

main.o: main.cpp Body.hpp
	g++ -c main.cpp -Wall -Werror -ansi -pedantic

clean:
	rm -rf NBody *.o *.~
