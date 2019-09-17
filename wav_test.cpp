/** \file Unit tests for WAV Module
 */
#include "catch.hpp"
#include "signal.hpp"
#include "wav.hpp"

TEST_CASE( "testing wav writer", "[wav]" ) {
	Signal s(44100);
	s.push_back(1);
	s.push_back(2);
	s.normalize();
	string output = "file";
	bool ok = write_wav(s, output);
	REQUIRE(ok == true);
}

TEST_CASE("testing wav writer again", "[wav]") {
	Signal s(44100);
	
	s.push_back(0);
	s.push_back(5);
	s.push_back(6);
	s.push_back(7);
	s.push_back(8);
	s.normalize();
	string output = "file";
	bool ok = write_wav(s, output);
	REQUIRE(ok == true);
}

TEST_CASE("lets test some more because why not", "[wav]") {
	Signal s(44100);
	
	s.push_back(55);
	s.push_back(4864);
	s.push_back(5545);
	s.push_back(5545);
	s.push_back(5485);
	s.push_back(553);
	s.normalize();
	string output = "file";
	bool ok = write_wav(s, output);
	REQUIRE(ok == true);
}
