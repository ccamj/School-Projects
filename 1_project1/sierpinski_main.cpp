#include <SFML/Graphics.hpp>
#include <iostream>
#include <cmath>
#include "sierpinski.hpp"

int main(int argc, char* argv[]){
	if (argc < 3) {
		std::cout << "Please enter 2 integer parameters: [depth] + [size]\n";
		return -1;
	}
	//string to int
	int depth = atoi(argv[1]);
	int size = atoi(argv[2]);

	//calculate equilateral triangle height
	int height = size/2 * sqrt(3);
	
	sf::Vector2f top(size/2, 0);
	sf::Vector2f left(0, height);
	sf::Vector2f right(size, height);
	Sierpinski s(top, left, right, depth);

	sf::RenderWindow window(sf::VideoMode(size, height), "Sierpinski triangle");

	while (window.isOpen()) {
		sf::Event event;
		while (window.pollEvent(event)) {
			if (event.type == sf::Event::Closed) {
				window.close();
				break;
			}
		}
		window.clear();
		window.draw(s);
		window.display();
	}
	return 0;
}