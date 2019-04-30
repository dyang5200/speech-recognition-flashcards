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

	// Analyze the user's speech
	user_speech = speech_analyzer.AnalyzeSpeech(AUDIO_FILEPATH);

	cout << "User's Speech: " << user_speech << endl;
}

//--------------------------------------------------------------
void ofApp::update() {

}

//--------------------------------------------------------------
void ofApp::draw() {
	if (draw_instructions) {
		drawInstructions();
	}
	else {
		ofClear(255);
		ofBackground(r_value, g_value, b_value);
		ofSetHexColor(0xFFFFFF);
		ofDrawRectRounded(card_rect, 10);
		ofSetHexColor(0x000000);
		lato_font.drawString(flashcard_list[flashcard_list_index], 440, 390);

		ofSetHexColor(0xFFFFFF);
		lato_light.drawString(INSTRUCTION_TAG, 370, 680);
	}
}

void ofApp::drawInstructions() {
	ofSetHexColor(0xFFFFFF);
	ofDrawRectRounded(card_rect, 10);
	ofSetHexColor(0x000000);
	lato_font.drawString(WELCOME_MESSAGE, 190, 300);
	lato_light.drawString(RECORD_INSTRUCTIONS, 220, 400);
	lato_light.drawString(NAVIG_INSTRUCTIONS, 190, 430);


	ofSetHexColor(0xFFFFFF);
	lato_light.drawString(INSTRUCTION_TAG, 370, 680);
}

void ofApp::setBackground(int r_value, int g_value, int b_value) {
	ofSetBackgroundColor(r_value, g_value, b_value);
}

void ofApp::resetBackground() {
	int r_value = R_ORIGINAL;
	int g_value = G_ORIGINAL;
	int b_value = B_ORIGINAL;
}

//--------------------------------------------------------------
void ofApp::keyPressed(int key) {
	// Background turns green if correct, red if incorrect
	if (key == 'o') {
		r_value = 99;
		g_value = 242;
		b_value = 109;
	} else if (key == 'x') {
		r_value = 253;
		g_value = 38;
		b_value = 38;
	} else if (key == 'd') {
		resetBackground();
		draw_instructions = false;
		if (flashcard_list_index == flashcard_list.size() - 1) {
			flashcard_list_index = 0;
		} else {
			flashcard_list_index++;
		}
	} else if (key == 'a') {
		resetBackground();
		draw_instructions = false;
		if (flashcard_list_index == 0) {
			flashcard_list_index = flashcard_list.size() - 1;
		}
		else {
			flashcard_list_index--;
		}
	} else if (key == 'p') {
		mySound.play();
	} else if (key == 'i') {
		resetBackground();
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
