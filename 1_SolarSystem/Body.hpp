/*
 * Body.hpp
 *
 *  Created on: Oct 5, 2016
 *      Author: cam
 */

#ifndef BODY_HPP_
#define BODY_HPP_
#include <SFML/Graphics.hpp>

#define _G 6.67e-11 //Gravitational constant

class Body : public sf::Drawable
{
	public:
		Body(double scale, int size);
		~Body();
		void init();
		void step(double time_scale);
		void setForce(double m2, double r);
		void setForceX(double deltaX, double r);
		void setForceY(double deltaY, double r);
		void flushForce();
		double getMass();
		double getXPos();
		double getYPos();

	private:
		void virtual draw(sf::RenderTarget& target, sf::RenderStates states) const;
		friend std::istream& operator>> (std::istream& in, Body& body);
		sf::Sprite _sprite;
		sf::Texture _texture;
		double _x,_y, _velx, _vely, _mass, _scale;
		double _force, _forcex, _forcey;
		int _size;
		std::string _name;
};
#endif// BODY_HPP_

