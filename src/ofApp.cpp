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

bool ofApp::isCorrect() {
	return (user_speech == flashcard_list[flashcard_list_index]);
}

void ofApp::setup() {
	// Load flashcard text fonts
	lato_font.load(LATO_FONT_PATH, 25);
	lato_light.load(LATO_LIGHT_PATH, 18);

	// Set up flashcard GUI application
	mySound.load(SOUND_PATH);
	setFlashcardList();
	ofBackground(38, 135, 154);

	// Set up card rectangle
	card_rect.x = 100;
	card_rect.y = 125;
	card_rect.width = 800;
	card_rect.height = 500;

	//gui.setup(); // most of the time you don't need a name
	//gui.add(filled.setup("fill", true));
	//gui.add(radius.setup("radius", 140, 10, 300));
	//gui.add(center.setup("center", ofVec2f(ofGetWidth() * .5, ofGetHeight() * .5), ofVec2f(0, 0), ofVec2f(ofGetWidth(), ofGetHeight())));
	//gui.add(color.setup("color", ofColor(100, 100, 140), ofColor(0, 0), ofColor(255, 255)));
	//gui.add(circleResolution.setup("circle res", 5, 3, 90));
	//gui.add(twoCircles.setup("two circles"));
	//gui.add(ringButton.setup("ring"));
	//gui.add(screenSize.setup("screen size", ofToString(ofGetWidth()) + "x" + ofToString(ofGetHeight())));

	// Analyze the user's speech
	user_speech = speech_analyzer.AnalyzeSpeech(AUDIO_FILEPATH);

	cout << "User's Speech: " << user_speech << endl;
}

//--------------------------------------------------------------
void ofApp::update() {

}

//--------------------------------------------------------------
void ofApp::draw() {
	drawInstructions();

	// Draw the GUI
	gui.draw();

	if (draw_next) {
		drawNextCard();
		draw_next = false;
	} else if (draw_instructions) {
		drawInstructions();
		draw_instructions = false;
	}
}

void ofApp::drawNextCard() {
	ofClear(255);
	ofBackground(38, 135, 154);
	ofSetHexColor(0xFFFFFF);
	ofDrawRectRounded(card_rect, 10);
	ofSetHexColor(0x000000);
	lato_font.drawString(flashcard_list[flashcard_list_index], 440, 390);

	ofSetHexColor(0xFFFFFF);
	lato_light.drawString("Press 'i' for instructions", 370, 680);
}

void ofApp::drawInstructions() {
	ofSetHexColor(0xFFFFFF);
	ofDrawRectRounded(card_rect, 10);
	ofSetHexColor(0x000000);
	lato_font.drawString(WELCOME_MESSAGE, 190, 300);
	lato_light.drawString(RECORD_INSTRUCTIONS, 220, 400);
	lato_light.drawString(NAVIG_INSTRUCTIONS, 190, 430);


	ofSetHexColor(0xFFFFFF);
	lato_light.drawString("Press 'i' for instructions", 370, 680);
	//ofDrawTriangle(100, 360, 100, 400, 75, 380);
	//ofDrawTriangle(900, 360, 925, 380, 900, 400);
}


//--------------------------------------------------------------
void ofApp::keyPressed(int key) {
	// Background turns green if correct, red if incorrect
	if (key == 'o') {
		ofSetBackgroundColor(99, 242, 109);
	} else if (key == 'x') {
		ofSetBackgroundColor(253, 38, 38);
	} else if (key == 'd') {
		if (flashcard_list_index == -1) {
			draw_next = true;
			flashcard_list_index++;
		}
		else if (flashcard_list_index == flashcard_list.size() - 1) {
			flashcard_list_index = 0;
		}
		else {
			flashcard_list_index++;
		}
	} else if (key == 'a') {
		if (flashcard_list_index == 0) {
			flashcard_list_index = flashcard_list.size() - 1;
		}
		else {
			flashcard_list_index--;
		}
	} else if (key == 'p') {
		mySound.play();
	} else if (key == 'i') {
		draw_instructions = true;
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
