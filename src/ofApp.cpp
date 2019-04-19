#include "ofApp.h"

void ofApp::setup() {
	SpeechAnalyzer speech_analyzer;

	cout << "Lexical: " << lexical << endl;
}

void ofApp::draw() {
    ofBackgroundGradient(ofColor::white, ofColor::black);
    ofDrawBitmapStringHighlight("See console for output.", ofPoint(30, 30));
}
