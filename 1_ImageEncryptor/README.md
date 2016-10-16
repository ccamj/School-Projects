## Synopsis

A program to encrypt and decrypt an image file using my Left Feedback Shift Register. Works best with PNG, BMP and other non compressed image files.

## Installation

Please use the provided Makefile ($ make) to compile and link the source and object files.
To properly start the program please run the command $ ./ps2b [path to image input] [path to image output] [binary string] [tap integer]

ex:

make

./ps2b ./cat.png ./newcat.png 101010101010101001 8

## File Layout
Files:
PhotoMagic.cpp (main) - Handles input and output. Uses the LSFR class to encrypt the image then saves in to a new file

LFSR.cpp/hpp - Takes a binary string and a Tap and shifts each bit one over to the left from the Tap position.

Other files: Makefile, cat.png, screen_shot.png

## Library Reference

Simple Fast Media Library (SFML)
http://www.sfml-dev.org/download.php
Using SFML 2.1

