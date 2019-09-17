/** \file Unit tests for Signal Module
*/
#include "catch.hpp"

#include "signal.hpp"

TEST_CASE( "Testing signal constructor", "[signal]" ) {
	Signal s(44100);
	REQUIRE(s.getSampleRate() == 44100);
}

TEST_CASE("Testing signal ", "[signal]") {
	Signal s(44100);
	s.push_back(1);
	REQUIRE(s.size() == 1);
	s.push_back(2);
	s.normalize();
	REQUIRE(s.operator[](0) == 1);
	REQUIRE(s.operator[](1) == 2);
}

TEST_CASE("Testing another signal ", "[signal]") {
	Signal s(44100);
	int n = 0;
	while (n < 1000) {
		s.push_back(n);
		n++;
	}
	s.normalize();
	REQUIRE(s.size() == 1000);
	REQUIRE(s.operator[](0) == 0);
	REQUIRE(s.operator[](1) == 1);
	REQUIRE(s.operator[](2) == 2);
	REQUIRE(s.operator[](3) == 3);
	REQUIRE(s.operator[](4) == 4);
	REQUIRE(s.operator[](5) == 5);

}
