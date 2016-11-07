/* "Copyright [2016] <Cam>"  [legal/copyright]"
 * RingBuffer.hpp
 *
 *  Created on: Oct 24, 2016
 *      Author: cam
 */

#ifndef RINGBUFFER_HPP_
#define RINGBUFFER_HPP_

#include <stdint.h>

class RingBuffer {
 public:
        explicit RingBuffer(int capacity);
        virtual ~RingBuffer();
        int size();
        bool isEmpty();
        bool isFull();
        void enqueue(int16_t x);
        int16_t dequeue();
        int16_t peek();

 private:
        int _size, _head, _tail, _cap;
        int16_t* _buffer;
};

#endif /* RINGBUFFER_HPP_ */
