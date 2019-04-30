#pragma once
#include "ofMain.h"
#include "ofxGui.h"
#include <stdio.h>
#include <vector>
#include <string>
#include "SpeechAnalyzer.h"

#define AUDIO_FILEPATH "C:\\Users\\danie\\Downloads\\preamble10.wav"
#define LATO_FONT_PATH "C:\\Users\\danie\\of_v0.10.1_vs2017_release\\apps\\myApps\\final_project\\fonts\\Lato-Regular.ttf"
#define LATO_LIGHT_PATH "C:\\Users\\danie\\of_v0.10.1_vs2017_release\\apps\\myApps\\final_project\\fonts\\Lato-Light.ttf"
#define SOUND_PATH "C:\\Users\\danie\\of_v0.10.1_vs2017_release\\apps\\myApps\\final_project\\graphicsExample\\aahhh.wav"

#define WELCOME_MESSAGE "Welcome to Speech Recognition Flashcards!"
#define RECORD_INSTRUCTIONS "Press 'r' to begin recording. Press 'e' to end recording."
#define NAVIG_INSTRUCTIONS "Press 'd' to go to the next card and 'a' to go to the previous card."

using std::vector;
using std::string;

// Class the models the Speech Flashcards application (GUI)
class ofApp: public ofBaseApp {
	private:
		// A speech analyzer
		SpeechAnalyzer speech_analyzer;
		// A sound player
		ofSoundPlayer mySound;

		// Changes to true if we want to draw the next card. False otherwise
		bool draw_next = false;

		// Changes to true when we want to draw the instructions page.
		bool draw_instructions = false;

		// Remembers the index of the flashcard list (remembers which flashcard the user is currently on)
		int flashcard_list_index = -1;
		// A vector of all the flashcards
		vector<string> flashcard_list = vector<string>();
		
		// The user's speech
		string user_speech;

		// Flashcard text font
		ofTrueTypeFont lato_font;
		// Lighter font
		ofTrueTypeFont lato_light;

		// Rectangle for flashcard object in GUI
		ofRectangle card_rect;

		ofxFloatSlider radius;
		ofxColorSlider color;
		ofxVec2Slider center;
		ofxIntSlider circleResolution;
		ofxToggle filled;
		ofxButton twoCircles;
		ofxButton ringButton;
		ofxLabel screenSize;

		ofxPanel gui;

		ofSoundPlayer ring;

	public:
		// Populates the list of flashcards with desired words
		void setFlashcardList();
		// Draws the next card in the list of flashcards
		void drawNextCard();
		// Draws the instructions page
		void drawInstructions();
		// Returns true if the user's pronunciation is correct. False otherwise
		bool isCorrect();

		void setup();
		void update();
		void draw();

		void keyPressed(int key);
		void keyReleased(int key);
		void mouseMoved(int x, int y);
		void mouseDragged(int x, int y, int button);
		void mousePressed(int x, int y, int button);
		void mouseReleased(int x, int y, int button);
		void mouseEntered(int x, int y);
		void mouseExited(int x, int y);
		void windowResized(int w, int h);
		void dragEvent(ofDragInfo dragInfo);
		void gotMessage(ofMessage msg);
	};