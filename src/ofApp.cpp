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

void ofApp::setupRect() {
	card_rect.x = RECT_X;
	card_rect.y = RECT_Y;
	card_rect.width = WIDTH;
	card_rect.height = HEIGHT;
}

void ofApp::setup() {
	// Load flashcard text fonts
	lato_font.load(LATO_FONT_PATH, LATO_SIZE);
	lato_light.load(LATO_LIGHT_PATH, LATO_LIGHT_SIZE);

	// Load sounds
	mySound.load(SOUND_PATH);

	// Set up card rectangle and flashcard texts
	setupRect();
	setFlashcardList();

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
	} else {
		ofClear(bg_hex);
		ofBackgroundHex(bg_hex);
		ofSetHexColor(WHITE);
		ofDrawRectRounded(card_rect, RADIUS);
		ofSetHexColor(BLACK);
		lato_font.drawString(flashcard_list[flashcard_list_index], 440, 390);

		ofSetHexColor(WHITE);
		lato_light.drawString(INSTRUCTION_TAG, 370, 680);
	}
}

void ofApp::drawInstructions() {
	ofBackgroundHex(ORIGINAL_BG);
	ofSetHexColor(WHITE);
	ofDrawRectRounded(card_rect, RADIUS);
	ofSetHexColor(BLACK);
	lato_font.drawString(WELCOME_MESSAGE, 190, 300);
	lato_light.drawString(RECORD_INSTRUCTIONS, 220, 400);
	lato_light.drawString(NAVIG_INSTRUCTIONS, 190, 430);


	ofSetHexColor(WHITE);
	lato_light.drawString(INSTRUCTION_TAG, 370, 680);
}

//--------------------------------------------------------------
void ofApp::keyPressed(int key) {
	// Background turns green if correct, red if incorrect
	if (key == 'o') {
		bg_hex = CORRECT_HEX;
	} else if (key == 'x') {
		bg_hex = INCORRECT_HEX;
	} else if (key == NEXT_KEY) {
		bg_hex = ORIGINAL_BG;
		draw_instructions = false;
		if (flashcard_list_index == flashcard_list.size() - 1) {
			flashcard_list_index = 0;
		} else {
			flashcard_list_index++;
		}
	} else if (key == PREVIOUS_KEY) {
		bg_hex = ORIGINAL_BG;
		draw_instructions = false;
		if (flashcard_list_index == 0) {
			flashcard_list_index = flashcard_list.size() - 1;
		}
		else {
			flashcard_list_index--;
		}
	} else if (key == INSTRUCTIONS_KEY) {
		bg_hex = ORIGINAL_BG;
		draw_instructions = true;
	} else if (key == 'p') {
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
