all: proj

proj: GuitarHero.o GuitarString.o RingBuffer.o 
	 g++ GuitarHero.o GuitarString.o RingBuffer.o -o GuitarHero -lsfml-graphics -lsfml-window -lsfml-system -lsfml-audio

GuitarHero.o: GuitarHero.cpp RingBuffer.hpp GuitarString.hpp 
	g++ -c GuitarHero.cpp -Wall -Werror -ansi -pedantic

GuitarString.o: GuitarString.cpp RingBuffer.hpp GuitarString.hpp 
	g++ -c GuitarString.cpp -Wall -Werror -ansi -pedantic

RingBuffer.o: RingBuffer.cpp RingBuffer.hpp 
	g++ -c RingBuffer.cpp -Wall -Werror -ansi -pedantic

clean:
	rm -rf GuitarHero *.o *.~