#ifndef ORIGINAL_HPP
#define ORIGINAL_HPP
#include <SFML/Graphics.hpp>

class Original : public sf::Drawable
{
	public:
	
		//top left right points and depth
		Original(int radius, int x, int y, int depth);
		
		//destructor
		~Original();
		
	private:
		
		void virtual draw(sf::RenderTarget& target, sf::RenderStates states) const;
		

		sf::CircleShape circ;
		int _depth;
		float _radius, _next_radius;
		
		Original* _child1;
		Original* _child2;
		Original* _child3;
		Original* _child4;
};
#endif