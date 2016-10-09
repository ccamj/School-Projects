/*
 * Body.hpp
 *
 *  Created on: Oct 5, 2016
 *      Author: cam
 */

#ifndef BODY_HPP_
#define BODY_HPP_
#include <SFML/Graphics.hpp>

class Body : public sf::Drawable
{
	public:
		Body(double scale, int size);
		~Body();
		void init();

	private:
		void virtual draw(sf::RenderTarget& target, sf::RenderStates states) const;
		friend std::istream& operator>> (std::istream& in, Body& body);
		sf::Sprite _sprite;
		sf::Texture _texture;
		double _x,_y, _vel_x, _vel_y, _mass, _scale;
		int _size;
		std::string _name;
};
#endif// BODY_HPP_
