#include <SFML/Graphics.hpp>
#include <iostream>
#include <cmath>
#include "original.hpp"

int main(int argc, char* argv[]){
	if (argc < 3) {
		std::cout << "Please enter 2 integer parameters: [depth] + [radius]\n";
		return -1;
	}

	int depth = atoi(argv[1]);
	int diameter = atoi(argv[2]);
	int radius =diameter/2;
	
					// radius, x, y, depth
	Original circle(radius, radius, radius, depth);

	sf::RenderWindow window(sf::VideoMode(diameter, diameter), "Recursive Circle");

	while (window.isOpen()) {
		sf::Event event;
		while (window.pollEvent(event)) {
			if (event.type == sf::Event::Closed) {
				window.close();
				break;
			}
		}
		window.clear();
		window.draw(circle);
		window.display();
	}
	return 0;
}