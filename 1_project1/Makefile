all: sierp original

# ===== link objects to a binary
sierp: sierpinski_main.o sierpinski.o
	g++ sierpinski_main.o sierpinski.o -o sierpinski -lsfml-graphics -lsfml-window -lsfml-system

original: original_main.o original.o
	g++ original_main.o original.o -o original -lsfml-graphics -lsfml-window -lsfml-system

# =====compile source files to object files
sierpinski_main.o: sierpinski_main.cpp sierpinski.hpp
	g++ -c sierpinski_main.cpp sierpinski.cpp -Wall -Werror -ansi -pedantic

original_main.o: original_main.cpp original.hpp
	g++ -c original_main.cpp original.cpp -Wall -Werror -ansi -pedantic

clean:
	rm -rf sierpinski original *.o *.~