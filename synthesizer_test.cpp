/** \file Integration tests for synthesizer function.
*/
#include "catch.hpp"
#include "signal.hpp"
#include "track.hpp"
#include "synthesizer.hpp"

TEST_CASE( "Testing Synthesizer", "[synthesizer]" ) { 
	Track t(480);
	t.addTempoEvent(500000, 0);
	t.addNoteEvent(9, 62, 20, 100);
	t.addEndEvent(400);
	Signal s(44100);
	s = synthesize(t);
	REQUIRE(s.getSampleRate() == 44100);
}