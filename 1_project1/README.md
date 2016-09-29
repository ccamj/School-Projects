## File Layout
This project contains two programs which can be compiled and linked together with the Makefile.
Program1: sierpinski_main.cpp (main file), sierpinski.cpp, sierpinski.hpp
Program2: original_main.cpp (main file), original.cpp, original.hpp

Other files: Makefile, sierpinski_screenshot.png, original_screenshot.png

## Synopsis

This project contains fractals implemented through recursion. One is the popular Sierpinski's Triangle, the other is my own fractal, circles that each create 4 child circles.

## Installation

This project is set up for use on Linux. Use the provided Makefile ($ make Makefile) to compile and link the source and object files.
To properly start the program please run the command $ ./sierpinski [number of layers] [window size]

ex:

make Makefile

./sierpinski 4 600

./original 2 800

## Library Reference

Simple Fast Media Library (SFML)
http://www.sfml-dev.org/download.php
Using SFML 2.1
