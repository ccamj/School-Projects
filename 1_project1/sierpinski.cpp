#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <cmath>
#include "sierpinski.hpp"
 
void Sierpinski::draw(sf::RenderTarget& target, sf::RenderStates states) const {
	//draw base triangle
	target.draw(tri, states);
	
	//inner triangles
	sf::ConvexShape next_tri;
	next_tri.setFillColor(sf::Color::Black);
	next_tri.setPointCount(3);
	next_tri.setPoint(0, _nextA);
	next_tri.setPoint(1, _nextB);
	next_tri.setPoint(2, _nextC);
	if(_depth != 0)target.draw(next_tri, states);
	if(_child1 != NULL){
		_child1->draw(target,states);
		_child2->draw(target,states);
		_child3->draw(target,states);
		
	}
	
}

Sierpinski::Sierpinski(sf::Vector2f top, sf::Vector2f left, sf::Vector2f right, int depth) : _depth(depth){
	//set up base triangle
	tri.setPointCount(3);
	tri.setPoint(0, left);
	tri.setPoint(1, right);
	tri.setPoint(2, top);
	tri.setFillColor(sf::Color::White);
	
	//set up inner triangle
	_nextA = mid(top, left);
	_nextB = mid(left, right);
	_nextC = mid(right, top);
	
	int next_depth = _depth-1;

	if(next_depth > 0){
		_child1 = new Sierpinski(top, _nextA, _nextC, next_depth);
		_child2 = new Sierpinski(_nextA, left, _nextB, next_depth);
		_child3 = new Sierpinski(_nextC, _nextB, right, next_depth);
	}
	else{
		_child1 = _child2 = _child3 = NULL;
	}
}
// find mid point of two points. needed for drawing next triangles
sf::Vector2f Sierpinski::mid(sf::Vector2f p1, sf::Vector2f p2)
{
	return sf::Vector2f((p1.x + p2.x)/2, (p1.y + p2.y)/2);
}

Sierpinski::~Sierpinski(){
	if(_child1 != NULL){
		delete (_child1);
		delete (_child2);
		delete (_child3);
	}
}
