/* "Copyright [2016] <Cam>"  [legal/copyright]"
 * RingBuffer.cpp
 *
 *  Created on: Oct 24, 2016
 *      Author: cam
 */
#include <iostream>
#include <stdexcept>
#include "RingBuffer.hpp"

#define debug(x) std::cout <<  x << std::endl

RingBuffer::RingBuffer(int capacity):_cap(capacity) {
        if (_cap < 1)
                throw std::invalid_argument(
                        "RB constructor: capacity must be greater than zero.");

        _buffer = new int16_t[capacity];
        _size = _head = _tail = 0;
}

// return number of items currently in the buffer
int RingBuffer::size() {
        return _size;
}

// is the buffer empty (size equals zero)?
bool RingBuffer::isEmpty() {
        return (_size == 0);
}

// is the buffer full  (size equals capacity)?
bool RingBuffer::isFull() {
        return (_size == _cap);
}

// add item x to the end
void RingBuffer::enqueue(int16_t x) {
        if (isFull())
                throw std::runtime_error(
                        "enqueue: can't enqueue to a full ring.");

        _buffer[_tail] = x;
        _size++;
        _tail++;

        if (_tail == _cap)
                _tail = 0;
}

// delete and return item from the front
int16_t RingBuffer::dequeue() {
        if (isEmpty())
                throw std::runtime_error(
                        "dequeue: can't dequeue an empty buffer.");

        int16_t front = _buffer[_head];
        // _buffer[_head] = NULL;
        _size--;
        _head++;

        if (_head == _cap)
                _head = 0;

        return front;
}

// return (but do not delete) item from the front
int16_t RingBuffer::peek() {
        if (isEmpty())
                throw std::runtime_error(
                        "peek: can't peek an empty buffer.");

        return _buffer[_head];
}

RingBuffer::~RingBuffer() {
        delete[] _buffer;
}

