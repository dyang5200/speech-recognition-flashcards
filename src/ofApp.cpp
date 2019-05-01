#include "ofApp.h"

void ofApp::setFlashcardList() {
	flashcard_list.push_back("patrick");
	flashcard_list.push_back("joseph");
	flashcard_list.push_back("cynthia");
	flashcard_list.push_back("kim");
	flashcard_list.push_back("teju");
	flashcard_list.push_back("zeba");
	flashcard_list.push_back("aahhh");

	formatFlashcardList();
}

void ofApp::formatFlashcardList() {
	for (int i = 0; i < flashcard_list.size(); i++) {
		string first = flashcard_list[i].substr(0, 1);
		std::transform(first.begin(), first.end(), first.begin(), ::toupper);
		
		string rest = flashcard_list[i].substr(1);
		std::transform(rest.begin(), rest.end(), rest.begin(), ::tolower);

		string edited_text = first + rest;
		flashcard_list[i] = edited_text;
	}
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
	small_lato_light.load(LATO_LIGHT_PATH, SMALL_LIGHT_SIZE);

	// Set up card rectangle and flashcard texts
	setupRect();
	setFlashcardList();
}

void ofApp::recordAndAnalyze() {
	// Set up speech recognizer
	speech_tool.recognizeSpeech();

	// Analyzer user's speech
	user_speech = speech_tool.get_recognized_speech();
	cout << "User's Speech: " << user_speech << endl;

	changeBackground(isCorrect());
}

bool ofApp::isCorrect() {
	if (user_speech.length() == 0) {
		return false;
	}
	return (user_speech == flashcard_list[flashcard_list_index]);
}


void ofApp::draw() {
	ofClear(bg_hex);
	ofBackgroundHex(bg_hex);
	ofSetHexColor(WHITE);
	ofDrawRectRounded(card_rect, RADIUS);
	ofSetHexColor(BLACK);

	if (draw_instructions) {
		drawInstructions();
	} else {
		if (flashcard_list_index == -1) {
			lato_font.drawString(flashcard_list[0], 440, 390);
		} else {
			lato_font.drawString(flashcard_list[flashcard_list_index], 440, 390);
		}

		ofSetHexColor(WHITE);
		lato_light.drawString(INSTRUCTION_TAG, 380, 680);

		checkPlay();
		checkRecord();
	}
}

void ofApp::checkPlay() {
	if (play_count == 2) {
		if (isCorrect()) {
			speech_tool.synthesizeSpeech(CORRECT_FEEDBACK);
		} else {
			string feedback = INCORRECT_FEEDBACK;
			if (flashcard_list_index == -1) {
				feedback += flashcard_list[0];
			} else {
				feedback += flashcard_list[flashcard_list_index];
			}
			speech_tool.synthesizeSpeech(feedback);
		}

		play_count = 0;
	} else if (play_count == 1) {
		play_count++;
	}
}

void ofApp::checkRecord() {
	if (record_count == 2) {
		recordAndAnalyze();
		record_count = 0;
		play_count = 1;
	} else if (record_count == 1) {
		record_count++;
	}
}

void ofApp::drawInstructions() {
	lato_font.drawString(WELCOME_MESSAGE, 180, 300);
	lato_light.drawString(IMPROVE_TAG, 280, 410);
	lato_light.drawString(NAVIG_INSTRUCTIONS, 170, 450);
	small_lato_light.drawString(COPYRIGHT, 400, 600);
}

void ofApp::changeBackground(bool correct) {
	// Background turns green if correct, red if incorrect
	if (correct) {
		bg_hex = CORRECT_HEX;
	} else {
		bg_hex = INCORRECT_HEX;
	}

	ofBackground(bg_hex);
}

void ofApp::keyPressed(int key) {
	if (key == NEXT_KEY) {
		bg_hex = ORIGINAL_BG;
		draw_instructions = false;
		if (flashcard_list_index == flashcard_list.size() - 1) {
			flashcard_list_index = 0;
		} else {
			flashcard_list_index++;
		}
		record_count = 1;
	} else if (key == PREVIOUS_KEY) {
		bg_hex = ORIGINAL_BG;
		draw_instructions = false;
		if (flashcard_list_index == 0) {
			flashcard_list_index = flashcard_list.size() - 1;
		} else {
			flashcard_list_index--;
		}
		record_count = 1;
	} else if (key == INSTRUCTIONS_KEY) {
		bg_hex = ORIGINAL_BG;
		draw_instructions = true;
	}
}

void ofApp::update() {
	
}