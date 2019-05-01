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
	string text = "cat";
	speech_tool.synthesizeSpeech(text);
	
	//if (flashcard_list_index == -1) {
	//	speech_tool.synthesizeSpeech(flashcard_list[0]);
	//}
	//else {
	//	speech_tool.synthesizeSpeech(flashcard_list[flashcard_list_index]);
	//}

	// Load flashcard text fonts
	lato_font.load(LATO_FONT_PATH, LATO_SIZE);
	lato_light.load(LATO_LIGHT_PATH, LATO_LIGHT_SIZE);

	// Load sounds
	mySound.load(SOUND_PATH);

	// Set up card rectangle and flashcard texts
	setupRect();
	setFlashcardList();

	//// Analyze the user's speech
	//user_speech = speech_analyzer.AnalyzeSpeech(AUDIO_FILEPATH);
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
	
	cout << "|" << user_speech << "|" << endl;
	cout << "|" << flashcard_list[flashcard_list_index] << "|" << endl;

	if (user_speech.length() == 0) {
		return false;
	}

	cout << (user_speech == flashcard_list[flashcard_list_index]) << endl;
	return (user_speech == flashcard_list[flashcard_list_index]);
}


void ofApp::draw() {
	if (draw_instructions) {
		drawInstructions();
	} else {
		ofClear(bg_hex);
		ofBackgroundHex(bg_hex);
		ofSetHexColor(WHITE);
		ofDrawRectRounded(card_rect, RADIUS);
		ofSetHexColor(BLACK);

		if (flashcard_list_index == -1) {
			lato_font.drawString(flashcard_list[0], 440, 390);
		} else {
			lato_font.drawString(flashcard_list[flashcard_list_index], 440, 390);
		}

		ofSetHexColor(WHITE);
		lato_light.drawString(INSTRUCTION_TAG, 370, 680);

		//if (count == 2) {
		//	recordAndAnalyze();

		//	//if (flashcard_list_index == -1) {
		//	//	speech_tool.synthesizeSpeech(flashcard_list[0]);
		//	//} else {
		//	//	speech_tool.synthesizeSpeech(flashcard_list[flashcard_list_index]);
		//	//}

		//	count = 0;
		//}

		//if (count == 1) {
		//	count++;
		//}
	}
}

void ofApp::drawInstructions() {
	ofBackgroundHex(ORIGINAL_BG);
	ofSetHexColor(WHITE);
	ofDrawRectRounded(card_rect, RADIUS);
	ofSetHexColor(BLACK);
	lato_font.drawString(WELCOME_MESSAGE, 190, 300);
	lato_light.drawString(NAVIG_INSTRUCTIONS, 190, 400);
	lato_light.drawString(PLAY_SOUND_INSTR, 220, 440);


	ofSetHexColor(WHITE);
	lato_light.drawString(INSTRUCTION_TAG, 370, 680);
}

void ofApp::changeBackground(bool correct) {
	// Background turns green if correct, red if incorrect
	if (correct) {
		bg_hex = CORRECT_HEX;
	} else {
		bg_hex = INCORRECT_HEX;
	}
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
		count = 1;
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

void ofApp::update() {
	
}