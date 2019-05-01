#pragma once
#include "ofMain.h"
#include <stdio.h>
#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include "SpeechAnalyzer.h"
#include "Speech.h"

// File paths and fonts
#define AUDIO_FILEPATH "C:\\Users\\danie\\Downloads\\preamble10.wav"
#define SOUND_PATH "C:\\Users\\danie\\of_v0.10.1_vs2017_release\\apps\\myApps\\final_project\\graphicsExample\\aahhh.wav"
#define LATO_FONT_PATH "C:\\Users\\danie\\of_v0.10.1_vs2017_release\\apps\\myApps\\final_project\\fonts\\Lato-Regular.ttf"
#define LATO_LIGHT_PATH "C:\\Users\\danie\\of_v0.10.1_vs2017_release\\apps\\myApps\\final_project\\fonts\\Lato-Light.ttf"
#define LATO_SIZE 25
#define LATO_LIGHT_SIZE 18

// Strings that are displayed in the UI
#define WELCOME_MESSAGE "Welcome to Speech Recognition Flashcards!"
#define NAVIG_INSTRUCTIONS "Press 'd' to go to the next card and 'a' to go to the previous card."
#define PLAY_SOUND_INSTR "Press the spacebar to play the correct pronunciation."
#define INSTRUCTION_TAG "Press 'i' for instructions"

// Hexadecimal color codes
#define WHITE 0xFFFFFF
#define BLACK 0x000000
#define ORIGINAL_BG 0x23879A
#define CORRECT_HEX 0x60E55B
#define INCORRECT_HEX 0xFF5164

// Interactive key chars
#define NEXT_KEY 'd'
#define PREVIOUS_KEY 'a'
#define INSTRUCTIONS_KEY 'i'

// Rectangle properties
#define RECT_X 100
#define RECT_Y 125
#define WIDTH 800
#define HEIGHT 500
#define RADIUS 10

using namespace Microsoft::CognitiveServices::Speech;
using std::vector;
using std::string;

// Class the models the Speech Flashcards application (GUI)
class ofApp: public ofBaseApp {
	private:
		// Speech recognizer
		SpeechTool speech_tool;
		// A sound player
		ofSoundPlayer mySound;

		// Flashcard text font
		ofTrueTypeFont lato_font;
		// Lighter font
		ofTrueTypeFont lato_light;

		// Rectangle for flashcard object in GUI
		ofRectangle card_rect;

		// Background values
		int bg_hex = ORIGINAL_BG;

		// True when we want to draw the instructions page, false otherwise
		bool draw_instructions = true;

		// Remembers the index of the flashcard list (remembers which flashcard the user is currently on)
		int flashcard_list_index = -1;
		// A vector of all the flashcards
		vector<string> flashcard_list = vector<string>();
		
		// The user's speech
		string user_speech;

		// Helps draw new slide before running recordAndAnalyze()
		int count = 0;

	public:
		// Populates the list of flashcards with desired words
		void setFlashcardList();
		// Formats the text in flashcard list so the first letter is capitalized
		void formatFlashcardList();
		// Sets up rectangle
		void setupRect();
		// Draws the instructions page
		void drawInstructions();
		// Record and analyze user's speech
		void recordAndAnalyze();
		// Returns true if the user's pronunciation is correct. False otherwise
		bool isCorrect();
		// Changes the background to convey whether the user is correct or incorrect
		void changeBackground(bool correct);

		void setup();
		void update();
		void draw();

		void keyPressed(int key);
	};