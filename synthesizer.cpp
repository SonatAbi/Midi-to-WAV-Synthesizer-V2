#include "synthesizer.hpp"

// TODO

Signal synthesize(Track & track)
{
	DefaultInstrument ins(track);
	Signal curr(44100);
	double samp = 0;
	double saved = 0;

	double n = 0;
	int samprate = curr.getSampleRate();
	while (!ins.halted()) {
		double delta = n / samprate;
		
		samp = ins.sample(delta);
		if (samp == 1231) {
			curr.push_back(saved);
		}
		else {
			curr.push_back(samp);
		}
		saved = samp;
		
		n = n + 1;
	}
	
	curr.normalize();

	return curr;
}
