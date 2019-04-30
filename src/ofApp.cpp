#include "ofApp.h"

void ofApp::setFlashcardList() {
	flashcard_list.push_back("patrick");
	flashcard_list.push_back("joseph");
	flashcard_list.push_back("cynthia");
	flashcard_list.push_back("kim");
	flashcard_list.push_back("teju");
	flashcard_list.push_back("zeba");

	flashcard_list.push_back("aahhh");
}

void ofApp::setup() {
	// Set up flashcard GUI application
	mySound.load("C:\\Users\\danie\\of_v0.10.1_vs2017_release\\apps\\myApps\\final_project\\graphicsExample\\aahhh.wav");
	setFlashcardList();
	ofBackground(255, 255, 255);

	// Analyze the user's speech
	user_speech = speech_analyzer.AnalyzeSpeech(AUDIO_FILEPATH);

	cout << "User's Speech: " << user_speech << endl;
}

bool ofApp::isCorrect() {
	return true;
}

//--------------------------------------------------------------
void ofApp::update() {

}

//--------------------------------------------------------------
void ofApp::draw() {
	ofSetHexColor(0xAFEEEE);
	ofDrawRectangle(100, 125, 800, 500);
	ofSetHexColor(0x000000);
	ofDrawBitmapString("Welcome to Speech Recognition Flashcards!", 300, 350);
	ofDrawBitmapString("Press 'd' to go to the next card and 'a' to go to the previous card.", 230, 380);
	ofDrawTriangle(100, 360, 100, 400, 75, 380);
	ofDrawTriangle(900, 360, 925, 380, 900, 400);

	// add padding to arrows

	if (drawNext) {
		drawNextCard();
	}
}

void ofApp::drawNextCard() {
	ofClear(255);
	ofSetHexColor(0xAFEEEE);
	ofDrawRectangle(100, 125, 800, 500);
	ofSetHexColor(0x000000);
	ofDrawBitmapString(flashcard_list[flashcard_list_index], 450, 390);
	ofDrawTriangle(100, 360, 100, 400, 75, 380);
	ofDrawTriangle(900, 360, 925, 380, 900, 400);
}


//--------------------------------------------------------------
void ofApp::keyPressed(int key) {
	// Background turns green if correct, red if incorrect
	if (key == 'o') {
		ofSetBackgroundColor(99, 242, 109);
	}
	else if (key == 'x') {
		ofSetBackgroundColor(253, 38, 38);
	}
	else if (key == 'd') {
		if (flashcard_list_index == -1) {
			drawNext = true;
			flashcard_list_index++;
		}
		else if (flashcard_list_index == flashcard_list.size() - 1) {
			flashcard_list_index = 0;
		}
		else {
			flashcard_list_index++;
		}
	}
	else if (key == 'a') {
		if (flashcard_list_index == 0) {
			flashcard_list_index = flashcard_list.size() - 1;
		}
		else {
			flashcard_list_index--;
		}
	}
	else if (key == 'p') {
		mySound.play();
	}
}

//--------------------------------------------------------------
void ofApp::keyReleased(int key) {

}

//--------------------------------------------------------------
void ofApp::mouseMoved(int x, int y) {

}

//--------------------------------------------------------------
void ofApp::mouseDragged(int x, int y, int button) {
}

//--------------------------------------------------------------
void ofApp::mousePressed(int x, int y, int button) {

}

//--------------------------------------------------------------
void ofApp::mouseReleased(int x, int y, int button) {

}

//--------------------------------------------------------------
void ofApp::mouseEntered(int x, int y) {

}

//--------------------------------------------------------------
void ofApp::mouseExited(int x, int y) {

}

//--------------------------------------------------------------
void ofApp::windowResized(int w, int h) {

}

//--------------------------------------------------------------
void ofApp::gotMessage(ofMessage msg) {

}

//--------------------------------------------------------------
void ofApp::dragEvent(ofDragInfo dragInfo) {

}
