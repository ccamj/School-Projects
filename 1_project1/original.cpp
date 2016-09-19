#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <cmath>
#include "original.hpp"
 
void Original::draw(sf::RenderTarget& target, sf::RenderStates states) const {
	target.draw(circ, states);
	if(_child1 != NULL){
		_child1->draw(target,states);
		_child2->draw(target,states);
		_child3->draw(target,states);
		_child4->draw(target,states);
		
	}
	
}

Original::Original(int radius, int x, int y, int depth){
	//set up base triangle
	_radius = radius;
	_next_radius = radius/2;
	_depth = depth;
	
	circ.setRadius(radius);
	circ.setOrigin(radius, radius);
	circ.setPosition(x, y);
	circ.setOutlineThickness(2);
	
	// Create Variety for outline colors to differentiate layers.
	int R = 54, G = 106, B = 158;
	if(_depth > 0){
		R*=_depth;
		G=_depth*50;
		B-=_depth*50;
		if(R>255) R=255; if(G>255)G=255; if(B<0)B = 0;
	}
	circ.setOutlineColor(sf::Color(R,G,B,255));
	circ.setFillColor(sf::Color(255, 255, 255, 20)); //20 Opacity, again to differentiate layers
	

	if(_depth > 0){
		_child1 = new Original(_next_radius, x-_next_radius, y-_next_radius, _depth-1);
		_child2 = new Original(_next_radius,x+ _next_radius, y-_next_radius, _depth-1);
		_child3 = new Original(_next_radius, x-_next_radius, y+_next_radius, _depth-1);
		_child4 = new Original(_next_radius, x+_next_radius, y+_next_radius, _depth-1);
	}
	else{
		_child1 = _child2 = _child3 = _child4 = NULL;
	}
}

Original::~Original(){
	if(_child1 != NULL){
		delete (_child1);
		delete (_child2);
		delete (_child3);
		delete (_child4);
	}
}
