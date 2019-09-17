// TODO: implement the main entry point for synth here
#include <iostream>
#include <vector>
#include <string>
#include "synthesizer.hpp"
#include "signal.hpp"
#include "wav.hpp"
#include "track.hpp"
#include "midi.hpp"

using namespace std;

int main(int argc, char *argv[]) {
	string input;
	string output;
	std::vector<std::string>  arguments;
	for (int i = 0; i < argc; ++i) arguments.push_back(argv[i]);
	if (argc == 3) {
		input = argv[1];
		output = argv[2];
	}
	else {
		std::cerr << "Error: Wrong Command Line Arguments" << endl;
		return EXIT_FAILURE;
	}
	TrackListType tracklist = readMIDIFromFile(input);
	Track t = tracklist.front();
	Signal curr = synthesize(t);
	write_wav(curr, output);

	return EXIT_SUCCESS;
}