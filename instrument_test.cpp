/** \file Unit tests for DefaultInstrument Module
*/
#include "catch.hpp"
#include "signal.hpp"
#include "track.hpp"
#include "instrument.hpp"

TEST_CASE("Tested instrument halt", "[track]") {

	Track t(480);
	t.addTempoEvent(500000, 0);
	t.addNoteEvent(9, 62, 20, 100);
	t.addEndEvent(400);
	Signal curr(44100);
	DefaultInstrument i(t);
	double samp;
	samp = i.sample(1 / 44100);
	
	REQUIRE(samp == 0);
	REQUIRE(i.halted() == false);
}

TEST_CASE("Tested instrument", "[track]") {

	Track t(480);
	t.addTempoEvent(500000, 0);
	t.addNoteEvent(9, 62, 20, 100);
	t.addEndEvent(400);
	Signal curr(44100);
	DefaultInstrument i(t);
	double n = 0;
	double samp = 0;
	samp = i.sample(1 / 44100);
	while (!i.halted()) {
		double delta = n / 44100;
		samp = i.sample(delta);
		curr.push_back(samp);
		n = n + 1;
	}

	REQUIRE(i.halted() == true);
}

TEST_CASE("Tested instrument with other notes", "[track]") {

	Track t(560);
	t.addTempoEvent(500000, 0);
	t.addNoteEvent(9, 62, 20, 100);
	t.addNoteEvent(8, 62, 20, 200);
	t.addNoteEvent(9, 63, 20, 300);
	t.addNoteEvent(8, 63, 20, 400);
	t.addNoteEvent(9, 64, 20, 500);
	t.addNoteEvent(8, 64, 20, 600);
	t.addEndEvent(800);
	Signal curr(44100);
	DefaultInstrument i(t);
	double n = 0;
	double samp = 0;
	samp = i.sample(1 / 44100);
	while (!i.halted()) {
		double delta = n / 44100;
		samp = i.sample(delta);
		curr.push_back(samp);
		n = n + 1;
	}

	REQUIRE(i.halted() == true);
}
TEST_CASE("Tested instrument with other notes again", "[track]") {

	Track t(480);
	t.addTempoEvent(500000, 0);
	t.addNoteEvent(9, 62, 20, 100);
	t.addNoteEvent(8, 62, 20, 200);
	t.addNoteEvent(9, 70, 20, 300);
	t.addNoteEvent(8, 70, 20, 400);
	t.addNoteEvent(9, 80, 20, 500);
	t.addNoteEvent(8, 80, 20, 600);

	t.addEndEvent(800);
	Signal curr(44100);
	DefaultInstrument i(t);
	double n = 0;
	double samp = 0;
	samp = i.sample(1 / 44100);
	while (!i.halted()) {
		double delta = n / 44100;
		samp = i.sample(delta);
		curr.push_back(samp);
		n = n + 1;
	}

	REQUIRE(i.halted() == true);
}