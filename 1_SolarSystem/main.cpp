/*============================================================================
* Name        : main.cpp
* Author      : cam campbell
* Date        :
* Description : Animated demo of the solar system
============================================================================*/
#include <SFML/Graphics.hpp>
#include <iostream>
#include <sstream>
#include <cmath>
#include "Body.hpp"

#define DEBUG(x) std::cout << x << std::endl

// prototype for displaying time
std::string drawText(int sec);

int main(int argc, char* argv[]) {
	#define size 950 // window size
	std::vector<Body> bodies;
	double radius, scale;
	int num;

	if(argc < 3){
		std::cout << "invalid argument count" << std::endl
				<< "please use: \"./NBody [time] [time scale] < planets.txt\"" << std::endl;
		return -1;
	}

	double time = atoi(argv[1]);
	double time_scale = atoi(argv[2]);

	std::cin >> num >> radius;
	scale = (radius*2) / size;

	for(int i=0;i<num;i++){
		bodies.push_back(*new Body(scale, size));
		std::cin >> bodies[i];
	}

	for(int i=0;i<num;i++)
		bodies[i].init();


	sf::RenderWindow window(sf::VideoMode(size, size), "Solar System");
	int seconds = 1;
	while(window.isOpen())
	{
		sf::Event event;
		window.setFramerateLimit(100); // 100 is a nice speed
		while (window.pollEvent(event)) {
			if (event.type == sf::Event::Closed) {
				window.close();
				break;
			}
		}

		window.clear();
		if(seconds<time){
			for(int i=0;i<num;i++){
				bodies[i].flushForce();

				for(int t=0; t<num; t++){
					if(t==i) continue;
					double deltaX = bodies[t].getXPos() - bodies[i].getXPos();
					double deltaY = bodies[t].getYPos() - bodies[i].getYPos();
					double r = sqrt(pow(deltaX, 2) + pow(deltaY, 2)); // a^2 + b^2 = c^2
					bodies[i].setForce(bodies[t].getMass(), r);
					bodies[i].setForceX(deltaX, r);
					bodies[i].setForceY(deltaY, r);

				}
				bodies[i].step(time_scale);
				window.draw(bodies[i]);
			}
			seconds += time_scale;
		}
		// using this if-else so the motion can stop and the window can stay open
		else{
			for(int i=0;i<num;i++)
				window.draw(bodies[i]);
		}
		// time data display
		std::string str = drawText(seconds);
		sf::Font font;
		font.loadFromFile("nbody/font.ttf");
		sf::Text text(str, font), percentText("", font);
		text.setPosition(5, size - 115);
		text.setCharacterSize(18);

		// percent display
		int percent = seconds/(time/100);
		std::stringstream percStream;
		percStream << "\t[" << percent << "%]";
		percentText.setString(percStream.str());
		percentText.setPosition(size-percentText.getLocalBounds().width -5, size-40);

		window.draw(text);
		window.draw(percentText);
		window.display();
	}
	return 0;
}

// display time information
std::string drawText(int sec){
	int min, hour, day, week, month, year;
	std::stringstream time;

	min   = (sec/60) % 60;
	hour  = (sec/60/60) % 24 + 1;
	day   = (sec/60/60/24) % 7 + 1;
	week  = (sec/60/60/24/7) % 4 + 1;
	month = (int)(sec/60/60/24/30.416666) % 12 + 1; //cast int to have a decimal for precise rounding
	year  = (sec/60/60/24/365);

	time
	<< "Years:   " << year  << std::endl
	<< "Months:  " << month << std::endl
	<< "Weeks:   " << week  << std::endl
	<< "Days:    " << day   << std::endl
	<< "Hours:   " << hour  << std::endl
	<< "Minutes: " << min;
	
	return time.str();
}

