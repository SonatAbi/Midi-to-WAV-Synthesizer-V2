/** \file Unit tests for Event Module
*/
#include "catch.hpp"

#include "event.hpp"

TEST_CASE("Tested default tempoevent", "[tempoevent]") {

	TempoEvent t;
	REQUIRE(t.getTempo() == 500000);

}

TEST_CASE("Tested tempoevent", "[tempoevent]") {

	TempoEvent t(100);
	REQUIRE(t.getTempo() == 100);

}

TEST_CASE("Tested noteevent", "[noteevent]") {

	NoteEvent t(true, 60, 20);
	REQUIRE(t.getNoteOn() == true);
	REQUIRE(t.getNoteNumber() == 60);
	REQUIRE(t.getNoteVelocity() == 20);

}

TEST_CASE("Test Constructor 1 and TempoEvent", "[MIDIEvent]") {
	TempoEvent t(1000);
	MIDIEvent m(t, 200);

	REQUIRE(m.getTickTime() == 200);
	REQUIRE(m.isTempoEvent());
	REQUIRE(!m.isEndTrackEvent());
	REQUIRE(!m.isNoteEvent());
	REQUIRE(m.asTempoEvent().getTempo() == 1000);
}

TEST_CASE("Test tick", "[TickTime]")
{
	MIDIEvent a(TempoEvent(), 55);

	REQUIRE(a.getTickTime() == 55);
}

TEST_CASE("Tested midievent", "[midievent]") {
	TempoEvent t(100);
	MIDIEvent a(t, 100);
	REQUIRE(a.getTickTime() == 100);
	REQUIRE(a.isTempoEvent() == true);
	REQUIRE(a.asTempoEvent().getTempo() == 100);
	
	NoteEvent y(true, 60, 20);
	MIDIEvent b(y, 100);
	REQUIRE(b.isNoteEvent() == true);
	REQUIRE(b.asNoteEvent().getNoteNumber() == 60 );
	REQUIRE(b.asNoteEvent().getNoteOn() == true);
	REQUIRE(b.asNoteEvent().getNoteVelocity() == 20);

	EndTrackEvent u;
	MIDIEvent c(u, 300);
	REQUIRE(c.isEndTrackEvent() == true);
}