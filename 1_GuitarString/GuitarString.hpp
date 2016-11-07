/* "Copyright [2016] <cam>"
 * GuitarString.hpp
 *
 *  Created on: Nov 2, 2016
 *      Author: cam
 */

#ifndef GUITARSTRING_HPP_
#define GUITARSTRING_HPP_

#include <SFML/System.hpp>
#include <vector>
#include "RingBuffer.hpp"

class GuitarString {
 public:
        GuitarString();
        virtual ~GuitarString();

        explicit GuitarString(double frequency);
        explicit GuitarString(std::vector<sf::Int16> init);
        void pluck();
        void tic();
        sf::Int16 sample();
        int time();

 private:
        int _step, _cap;
        RingBuffer* _buffer;
};

#endif /* GUITARSTRING_HPP_ */

