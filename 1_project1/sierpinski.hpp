#ifndef SIERPINSKI_HPP
#define SIERPINSKI_HPP
#include <SFML/Graphics.hpp>

class Sierpinski : public sf::Drawable
{
	public:
	
		//top left right points and depth
		Sierpinski(sf::Vector2f top, sf::Vector2f right, sf::Vector2f left, int depth);
		
		sf::Vector2f mid(sf::Vector2f, sf::Vector2f);
		
		//destructor
		~Sierpinski();
		
	private:
		
		void virtual draw(sf::RenderTarget& target, sf::RenderStates states) const;

		//store next points
		sf::Vector2f _nextA, _nextB, _nextC;

		sf::ConvexShape tri;
		int _depth;
		
		Sierpinski* _child1;
		Sierpinski* _child2;
		Sierpinski* _child3;
};
#endif