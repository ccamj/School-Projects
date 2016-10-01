#include <SFML/Graphics.hpp>
#include <iostream>
#include "LFSR.hpp"

int main(int argc, char* argv[]) {
	std::string in_file, out_file;
	
	// check for correct amount of args
	if (argc < 4) {
		std::cout << "Please use the following:\n" << argv[0] 
		<< " [\"/path/to/image.png\"] [\"path/to/output.png\"] [BitString] [Tap]" << std::endl;
		return -1;
	}else{
		in_file = argv[1];
		out_file = argv[2];
	}

	// load up our input image
	sf::Image in_image, out_image;
	if (!in_image.loadFromFile(in_file)){
		std::cout << "Not a valid image file.\n"
		<< ".png or .bmp format is recommended for best decryption quality" << std::endl;
		return -1;
	}
	// copy input image to output image
	out_image = in_image;

	LFSR lfsr(argv[3], atoi(argv[4])); //Bit string, Tap
	
	// modify output image pixel by pixel
	sf::Color pixelColor;
	for(int x = 0; x < out_image.getSize().x; x++){
		for(int y = 0; y < out_image.getSize().y; y++){
			pixelColor = out_image.getPixel(x, y);
			pixelColor.r ^= lfsr.generate(8);
			pixelColor.b ^= lfsr.generate(8);
			pixelColor.g ^= lfsr.generate(8);
			out_image.setPixel(x, y, pixelColor);
		}
	}
	//save output image after modifying
	if (!out_image.saveToFile(out_file))
		return -1;

	// textures
	sf::Texture in_txt, out_txt;
	in_txt.loadFromImage(in_image);
	out_txt.loadFromImage(out_image);

	// sprites
	sf::Sprite in_sprite, out_sprite;
	in_sprite.setTexture(in_txt);
	out_sprite.setTexture(out_txt);

	// windows
	sf::RenderWindow window(sf::VideoMode(in_image.getSize().x, in_image.getSize().y), in_file);
	sf::RenderWindow window2(sf::VideoMode(out_image.getSize().x, out_image.getSize().y), out_file);

	while (window.isOpen() && window2.isOpen()) {
		sf::Event event;
		while (window.pollEvent(event)) {
			if (event.type == sf::Event::Closed)
				window.close();
		}
		while (window2.pollEvent(event)) {
			if (event.type == sf::Event::Closed)
				window2.close();
		}
		window.clear();
		window.draw(in_sprite);
		window.display();
		window2.clear();
		window2.draw(out_sprite);
		window2.display();
	}

	return 0;
}
