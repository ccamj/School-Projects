## Synopsis

Takes real world celestial body data from text files (ex. planets.txt and binary.txt) and runs that information through a solar system simulation using Newton's Laws of Force to calculate gravity, creating orbits, slingshots, etc.

One text file is designed to create the first 4 planets of our solar system and the sun (having all of the planets is just too big to scale down to a screen size and still be able to see)

The other text file creates a fictional binary star system created by me.

## Installation

Please use the provided Makefile ($ make) to compile and link the source and object files.
To properly start the program please run the command $ ./NBody [total time in seconds] [time step scale] < planets.txt

ex:

make

./NBody 157788000.0 25000.0 < binary.txt

./NBody 157788000.0 25000.0 < planets.txt

## File Layout
Files:

main.cpp (main) - Takes input from the provided text file and creates a vector of celestial bodies to store the data in.

Body.cpp/hpp celestial body class use to handle planetary motion data. Accepts data input from the text file using an overloaded input stream. This class then uses that data to calculate a net force between it and all other celestial bodies. From there an acceleration can be calculated and used to update the objects position.

Other files: Makefile, screenshot1.png, screenshot_custom.png, planets.txt, binary.txt
/nbody/: mercury.gif, venus.gif, earth.gif, mars.gif, sun.gif, coment.gif

## Library Reference

Simple Fast Media Library (SFML)

http://www.sfml-dev.org/download.php

Using SFML 2.1

