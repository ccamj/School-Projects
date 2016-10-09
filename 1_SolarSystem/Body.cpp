/*
 * Body.cpp
 *
 *  Created on: Oct 5, 2016
 *      Author: cam
 */

#include <SFML/Graphics.hpp>
#include <iostream>
#include "Body.hpp"

//set scale factor and window size
Body::Body(double scale, int size):
_scale(scale),
_size(size)
{
}

// set up the initial state for each body.
void Body::init(){
	_x /= _scale;
	_x += _size/2; // center x origin
	_y = _size/2 - _sprite.getLocalBounds().height/2; // center y origin
	_sprite.setPosition(_x, _y);

	_texture.loadFromFile("nbody/"+_name);// load from nbody folder
	_sprite.setTexture(_texture);
}

Body::~Body()
{
}

void Body::draw(sf::RenderTarget& target, sf::RenderStates states) const {
	target.draw(_sprite);
}

std::istream& operator>> (std::istream& in, Body& body) {
	in 
	>> body._x 
	>> body._y 
	>> body._vel_x 
	>> body._vel_y 
	>> body._mass 
	>> body._name;
	return in;
}

