/** \file Unit tests for Track Module
*/
#include "catch.hpp"

#include "track.hpp"

TEST_CASE("Tested default track", "[track]") {

	Track t;
	REQUIRE(t.getTicksPerBeat() == 500000);
}

TEST_CASE("Tested track", "[track]") {

	Track t(200000);
	REQUIRE(t.getTicksPerBeat() == 200000);
}

TEST_CASE("Tested track with tempo and note event", "[track]") {

	Track t(200000);
	t.addTempoEvent(1000, 100);
	REQUIRE(t.getTicksPerBeat() == 200000);

	REQUIRE(t.begin()->asTempoEvent().getTempo() == 1000);

	t.addNoteEvent(9, 56, 20, 200);
	
	Track::ConstIteratorType it = t.begin();
	
	REQUIRE(it->getTickTime() == 100);

	it++;

	REQUIRE(it->getTickTime() == 200);
}

TEST_CASE("Tested addtempoevent", "[track]") {

	Track t(480);
	t.addTempoEvent(5000, 200);

	REQUIRE(t.getTicksPerBeat() == 480);
	REQUIRE(t.begin()->getTickTime() == 200);
	REQUIRE(t.begin()->isTempoEvent());
	
	REQUIRE(!t.begin()->isEndTrackEvent());
	REQUIRE(t.begin()->asTempoEvent().getTempo() == 5000);
}

TEST_CASE("Tested track with endtrack and note event", "[track]") {

	Track t(30000);
	REQUIRE(t.getTicksPerBeat() == 30000);
	t.addNoteEvent(9, 56, 20, 200);
	REQUIRE(t.begin()->isNoteEvent() == true);
	REQUIRE(t.begin()->asNoteEvent().getNoteNumber() == 56);
	REQUIRE(t.begin()->asNoteEvent().getNoteOn() == true);
	REQUIRE(t.begin()->asNoteEvent().getNoteVelocity() == 20);

	Track::ConstIteratorType it = t.begin();
	t.addEndEvent(300);
	it++;
	REQUIRE(it->getTickTime() == 300);
	it++;
	REQUIRE(it == t.end());
}

TEST_CASE("Test begin()", "[track]")
{

	Track t;
	t.addTempoEvent(5000, 0);
	t.addNoteEvent(9, 72, 20, 100);
	t.addEndEvent(200);

	//check tempo event
	REQUIRE(t.begin()->getTickTime() == 0);
	REQUIRE(t.begin()->isTempoEvent());
	REQUIRE(t.begin()->asTempoEvent().getTempo() == 5000);


	auto it = t.begin();
	it++;
	//check note event
	REQUIRE(it->isNoteEvent());
	REQUIRE(!it->isTempoEvent());
	REQUIRE(!it->isEndTrackEvent());
	REQUIRE(it->getTickTime() == 100);
	REQUIRE(it->asNoteEvent().getNoteNumber() == 72);
	REQUIRE(it->asNoteEvent().getNoteVelocity() == 20);
	REQUIRE(it->asNoteEvent().getNoteOn());

	it++;
	//check end track event
	REQUIRE(it->isEndTrackEvent());
	REQUIRE(it->getTickTime() == 200);
}