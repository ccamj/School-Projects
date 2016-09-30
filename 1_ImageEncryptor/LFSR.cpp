#include <iostream>
#include <cmath>
#include "LFSR.hpp"

LFSR::LFSR(std::string seed, int tap){
	_seed = seed;
	_tap = tap;
}

int LFSR::step(){
	int x_or = _seed[0] ^ _seed[_seed.length() - _tap -1]; //bitwise op. ^ = XOR
	_seed.erase(0,1); //remove last bit (first character)
	_seed += x_or+48; //+48 converts ASCII value int to string
	return x_or;
}

int LFSR::generate(int k){
	int num = 0;
	for(int i=k; i>0; i--)
		if(step() == 1)
			num += pow(2, i-1);
	return num;
}

LFSR::~LFSR(){}

std::ostream& operator<< (std::ostream &out, LFSR &lfsr){
	out << lfsr._seed;
	return out;
}
