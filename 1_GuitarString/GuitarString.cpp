/* "Copyright [2016] <cam>"  [legal/copyright]
 * GuitarString.cpp
 *
 *  Created on: Nov 2, 2016
 *      Author: cam
 */

#include <SFML/System.hpp>
#include <math.h>  // c lib
#include <ctime>   // c++ libs
#include <vector>
#include "GuitarString.hpp"


// create a guitar string of the given frequency using a sampling rate of 44,100
GuitarString::GuitarString(double frequency) {
        _step = 0;
        _cap = ceil(44100/frequency);
        _buffer = new RingBuffer(_cap);
        while (!_buffer->isFull())
                _buffer->enqueue(0);
}
// create a guitar string with size and initial values are given by the vector
GuitarString::GuitarString(std::vector<sf::Int16> init) {
        _step = 0;
        _cap = init.size();
        _buffer = new RingBuffer(_cap);
        for (int i=0; !_buffer->isFull(); i++)
                _buffer->enqueue(init[i]);
}
// pluck the guitar string by replacing the
// buffer with random values, representing white noise
void GuitarString::pluck() {
        _buffer = new RingBuffer(_cap);


        while (!_buffer->isFull()) {
                sf::Int16 random = (sf::Int16)(rand() * 0xffff);
                _buffer->enqueue(random);
        }
}
// advance the simulation one time step
void GuitarString::tic() {
        sf::Int16 previous = _buffer->dequeue();
        _buffer->enqueue(.996 * .5 * (previous + _buffer->peek()));
        _step++;
}
// return the current sample
sf::Int16 GuitarString::sample() {
        return _buffer->peek();
}
// return number of times tic was called so far
int GuitarString::time() {
        return _step;
}

GuitarString::~GuitarString() {
        delete _buffer;
}

