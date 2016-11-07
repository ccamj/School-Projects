## Synopsis

A program that attributes a unique frequnecy to a given key press between 110 and 880 Hertz. After a key press the associated frequency is displayed in the window and a sound is played with respect to the key's frequency

The program works using the Karplus-Strong algorithm.

## Installation

Please use the provided Makefile ($ make) to compile and link the source and object files.
To properly start the program either  run the execuable or run the command $ ./GuitarHero

## File Layout
Files:

GuitarHero.cpp: (main file) assigns frequencies to key index's, catches key presses

RingBuffer.cpp: used as a Queue to store the sound buffer, giving sound feedback

GuitarString.cpp uses a RingBuffer, modeling a vibrating GuitarString

Other files: Makefile

## Library Reference

Simple Fast Media Library (SFML)

http://www.sfml-dev.org/download.php

Using SFML 2.1

--------------------------------------------------------------------
This assignment was formatted in accordance to cpplint style guide:

https://github.com/google/styleguide/tree/gh-pages/cpplint
