#include "ofApp.h"

void ofApp::setupRect() {
	card_rect.x = RECT_X;
	card_rect.y = RECT_Y;
	card_rect.width = WIDTH;
	card_rect.height = HEIGHT;
}

void ofApp::setup() {
	// Load flashcard text fonts and flashcard display
	lato_font.load(LATO_FONT_PATH, LATO_SIZE);
	lato_light.load(LATO_LIGHT_PATH, LATO_LIGHT_SIZE);
	small_lato_light.load(LATO_LIGHT_PATH, SMALL_LIGHT_SIZE);
	setupRect();

	// Prompt user and set up flashcards
	flashcards.setFlashcards();
	flashcard_list = flashcards.get_flashcards();
}

void ofApp::draw() {
	// Draws flashcard UI
	ofClear(bg_hex);
	ofBackgroundHex(bg_hex);
	ofSetHexColor(WHITE);
	ofDrawRectRounded(card_rect, RADIUS);
	ofSetHexColor(BLACK);

	// Draws text inside flashcard
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

		// Records and plays audio
		checkPlay();
		checkRecord();
	}
}

void ofApp::keyPressed(int key) {
	if (key == NEXT_KEY || key == PREVIOUS_KEY) {
		changeFlashcard(key);
	} else if (key == INSTRUCTIONS_KEY) {
		bg_hex = ORIGINAL_BG;
		draw_instructions = true;
	}
}

void ofApp::drawInstructions() {
	lato_font.drawString(WELCOME_MESSAGE, 180, 300);
	lato_light.drawString(IMPROVE_TAG, 280, 410);
	lato_light.drawString(NAVIG_INSTRUCTIONS, 170, 450);
	small_lato_light.drawString(COPYRIGHT, 400, 600);
}

void ofApp::recordAndAnalyze() {
	// Set up speech recognizer
	speech_tool.recognizeSpeech();

	// Analyzer user's speech
	user_speech = speech_tool.get_recognized_speech();

	changeBackground(isCorrect());
}

bool ofApp::isCorrect() {
	if (user_speech.length() == 0) {
		return false;
	}
	return (user_speech == flashcard_list[flashcard_list_index]);
}

void ofApp::checkPlay() {
	// Sets play_count to 0 after audio plays, and only increments play_count when play_count == 1
	// Only sets play_count = 1 in checkRecord(), 
	// which ensures feedback audio is played exactly once after user speaks.
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

int ofApp::changeBackground(bool correct) {
	// Background turns green if correct, red if incorrect
	if (correct) {
		bg_hex = CORRECT_HEX;
	} else {
		bg_hex = INCORRECT_HEX;
	}

	ofBackground(bg_hex);
	return bg_hex;
}

int ofApp::changeFlashcard(char key_pressed) {
	bg_hex = ORIGINAL_BG;
	draw_instructions = false;
	record_count = 1;

	if (key_pressed == NEXT_KEY) {
		if (flashcard_list_index == flashcard_list.size() - 1) {
			flashcard_list_index = 0;
		} else {
			flashcard_list_index++;
		}
	} else {
		if (flashcard_list_index == 0) {
			flashcard_list_index = flashcard_list.size() - 1;
		} else {
			flashcard_list_index--;
		}
	}

	return flashcard_list_index;
}