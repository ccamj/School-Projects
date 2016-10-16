/*
 * Body.cpp
 *
 *  Created on: Oct 5, 2016
 *      Author: cam
 */

#include <SFML/Graphics.hpp>
#include <iostream>
#include <cmath>
#include "Body.hpp"

// set scale factor and window size
Body::Body(double scale, int size):
_scale(scale),
_size(size)
{
}

// initialize texture and sprite
void Body::init(){
	_texture.loadFromFile("nbody/"+_name);// load from nbody folder
	_sprite.setTexture(_texture);
}

void Body::step(double time_scale){
	// F = ma		// a = F/m
	_velx += time_scale * (_forcex / _mass);
	_vely -= time_scale * (_forcey / _mass);

	_x += time_scale * _velx;
	_y -= time_scale * _vely;
	
	// scaling after calculations was important
	double x = _x / _scale;
	x += _size/2 - _sprite.getLocalBounds().width/2; // relative to center
	double y = _y / _scale;
	y += _size/2 - _sprite.getLocalBounds().height/2;
	_sprite.setPosition(x, y);
}

double Body::getXPos(){
	return _x;
}

double Body::getYPos(){
	return _y;
}

double Body::getMass(){
	return _mass;
}

void Body::setForce(double m2, double r){
	_force = _G * (_mass * m2) / pow(r,2);
}

void Body::setForceX(double deltaX, double r){
	_forcex += _force * (deltaX / r);
}

void Body::setForceY(double deltaY, double r){
	_forcey += _force * (deltaY / r);
}

// reset force vectors before moving bodies
void Body::flushForce(){
	_forcex = 0;
	_forcey = 0;
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
	>> body._velx
	>> body._vely
	>> body._mass
	>> body._name;
	return in;
}

