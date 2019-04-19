#include "ofApp.h"

void ofApp::setup() {
	std::string audio_as_str = ReadFile(AUDIO_FILEPATH);

	//std::cout << audio_as_str << endl;

	// Create new json object
	ofxJSONElement audio_as_json;
	bool success = audio_as_json.parse(audio_as_str);
	cout << "SUCCESS PARSING JSON? " << success << endl << endl;

	// Prints out recognized speech
	std::string lexical = audio_as_json["NBest"][0]["Lexical"].asString();
	cout << "Lexical: " << lexical << endl;
}

void ofApp::draw() {
    ofBackgroundGradient(ofColor::white, ofColor::black);
    ofDrawBitmapStringHighlight("See console for output.", ofPoint(30, 30));
}
