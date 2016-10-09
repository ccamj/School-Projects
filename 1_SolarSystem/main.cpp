/*============================================================================
* Name        : main.cpp
* Author      : cam campbell
* Version     :
* Copyright   : Your copyright notice
* Description : Static demo of the solar system
============================================================================*/
#include <SFML/Graphics.hpp>
#include <iostream>
#include "Body.hpp"
//using namespace std;

int main() {
	#define size 600 // window size
	std::vector<Body> bodies;
	double radius, scale;
	int num;

	std::cin >> num >> radius;

	scale = (radius*2) / size;
	
	for(int i=0;i<num;i++){
		bodies.push_back(*new Body(scale, size));
		std::cin >> bodies[i];
	}

	//the _texture pointer would be lost if I initialized it in the first loop
	for(int i=0;i<num;i++)
		bodies[i].init();

	sf::RenderWindow window(sf::VideoMode(size, size), "Solar System");
	while (window.isOpen()) {
		sf::Event event;
		while (window.pollEvent(event)) {
			if (event.type == sf::Event::Closed) {
				window.close();
				break;
			}
		}
		window.clear();

		for(int i=0;i<num;i++)
			window.draw(bodies[i]);
		window.display();
	}
	return 0;
}

