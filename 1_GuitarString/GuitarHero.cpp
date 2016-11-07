// "Copyright [2016] <cam>"

#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>
#include <SFML/Audio.hpp>
#include <SFML/Window.hpp>

#include <math.h>
#include <limits.h>

#include <iostream>
#include <sstream>
#include <string>
#include <exception>
#include <stdexcept>
#include <vector>

#include "RingBuffer.hpp"
#include "GuitarString.hpp"

// #define CONCERT_A 220.0
#define CONCERT_A 440.0  // Value from Princeton
#define SAMPLES_PER_SEC 44100
#define WIDTH 300
#define HEIGHT 200

std::vector<sf::Int16> makeSamplesFromString(GuitarString gs) {
        std::vector<sf::Int16> samples;
        gs.pluck();
        int duration = 8;  // seconds
        for (int i = 0; i < SAMPLES_PER_SEC * duration; i++) {
                gs.tic();
                samples.push_back(gs.sample());
        }
        return samples;
}

int main() {
        sf::RenderWindow window(sf::VideoMode(WIDTH, HEIGHT), "Guitar Hero");
        sf::Event event;
        double freq;
        int size = 37;
        std::vector<sf::SoundBuffer> buffers(size);
        std::vector<sf::Sound> sounds(size);
        std::vector<std::vector<sf::Int16> > samples(size);

        for (int i = 0; i < size; i++) {
                // Proper frequency calculation from Princeton
                freq = CONCERT_A * pow(2, (i-24.0)/12.0);
                GuitarString gs = GuitarString(freq);
                samples[i] = makeSamplesFromString(gs);
                buffers[i].loadFromSamples(&samples[i][0],
                        samples[i].size(),
                        2, SAMPLES_PER_SEC);
                sounds[i].setBuffer(buffers[i]);
        }

        sf::Font font;
        font.loadFromFile("./font.ttc");
        sf::Text text("", font);
        text.setCharacterSize(80);

        // Princeton's keyboard
        // std::string keys = "q2we4r5ty7u8i9op-[=zxdcfvgbnjmk,.;/' ";

        // I prefer the standard keys
        const std::string keys = "1234567890qwertyuiopasdfghjklzxcvbnm ";

        while (window.isOpen()) {
                while (window.pollEvent(event)) {
                        if (event.type == sf::Event::Closed) {
                                window.close();
                        } else if (event.type == sf::Event::TextEntered) {
                                int j = keys.find(event.text.unicode);
                                if (j != -1) {
                                        sounds[j].play();
                                        std::stringstream str;

                                        str
                                        << ceil(440*pow(2.0, (j-24.0)/12.0))
                                        << "Hz";
                                        text.setString(str.str());
                                        // cpplint requires this to look rediculous
                                        text.setPosition(
                                                WIDTH/2 -
                                                text.getLocalBounds().width/2,
                                                HEIGHT/2 -
                                                text.getLocalBounds().height/2);
                                }
                        }
                        window.clear();
                        window.draw(text);
                        window.display();
                }
        }
        return 0;
}

