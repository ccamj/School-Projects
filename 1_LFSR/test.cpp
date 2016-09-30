#include <iostream>
#include <string>

#include "LFSR.hpp"

#define BOOST_TEST_DYN_LINK
#define BOOST_TEST_MODULE Main
#include <boost/test/unit_test.hpp>

//Provided by UML
BOOST_AUTO_TEST_CASE(fiveBitsTapAtTwo) {

	LFSR l("00111",2);
	BOOST_REQUIRE(l.step()==1);
	BOOST_REQUIRE(l.step()==1);
	BOOST_REQUIRE(l.step()==0);
	BOOST_REQUIRE(l.step()==0);
	BOOST_REQUIRE(l.step()==0);
	BOOST_REQUIRE(l.step()==1);
	BOOST_REQUIRE(l.step()==1);
	BOOST_REQUIRE(l.step()==0);

	LFSR l2("00111", 2);
	BOOST_REQUIRE(l2.generate(8)==198);
}
//Midsized test. 10 bit string, tap at 4.
BOOST_AUTO_TEST_CASE(TenBitsTapAtFour) {

	LFSR l("1010110001",4);
	BOOST_REQUIRE(l.step()==0);
	BOOST_REQUIRE(l.step()==0);
	BOOST_REQUIRE(l.step()==1);
	BOOST_REQUIRE(l.step()==0);
	BOOST_REQUIRE(l.step()==0);
	BOOST_REQUIRE(l.step()==1);

	LFSR l2("1010110001", 4);
	BOOST_REQUIRE(l2.generate(6)==9);
}
//Larger 32 bit test. Tap at 7
BOOST_AUTO_TEST_CASE(thirtytwoBitsTapAtSeven) {
	LFSR l("01011010000110000010101000110010",7);

	BOOST_REQUIRE(l.step()==0);
	BOOST_REQUIRE(l.step()==1);
	BOOST_REQUIRE(l.step()==1);
	BOOST_REQUIRE(l.step()==0);
	BOOST_REQUIRE(l.step()==1);
	BOOST_REQUIRE(l.step()==0);
	BOOST_REQUIRE(l.step()==0);
	BOOST_REQUIRE(l.step()==0);
	BOOST_REQUIRE(l.step()==0);
	BOOST_REQUIRE(l.step()==1);
	BOOST_REQUIRE(l.step()==1);
	BOOST_REQUIRE(l.step()==1);
	BOOST_REQUIRE(l.step()==0);
	BOOST_REQUIRE(l.step()==0);
	BOOST_REQUIRE(l.step()==0);

	LFSR l2("01011010000110000010101000110010", 7);
	BOOST_REQUIRE(l2.generate(14)==6684);
}

