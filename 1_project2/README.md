## File Layout
This project contains a single program which can be compiled with the Makefile.
Source Files: test.cpp (main file), LFSR.cpp, LFSR.hpp

Other files: Makefile, and screen shots

## Synopsis

This project will accept 2 parameters when running from command line: a binary string, and a tap. The left feedback shift register will shift the bits over from the tap position to the left. This program is ran through Boos Test Framework for debugging.

## Installation

This project was set up for use on Linux. Use the provided Makefile ($ make) to compile and link the source and object files.
Please run the program with the command line $./ps2a in order to view the correct output

ex:

make

./ps2a

## Library Reference

Simple Fast Media Library (SFML)
http://www.sfml-dev.org/download.php
Using SFML 2.1

Boost Test Framework
http://www.boost.org/doc/libs/1_42_0/libs/test/doc/html/utf/intro.html
