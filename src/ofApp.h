#pragma once
#include "ofMain.h"
#include <stdio.h>
#include <vector>
#include <string>
#include "SpeechAnalyzer.h"

#define AUDIO_FILEPATH "C:\\Users\\danie\\Downloads\\preamble10.wav"

using std::vector;
using std::string;

// Class the models the Speech Flashcards application (GUI)
class ofApp: public ofBaseApp {
	private:
		SpeechAnalyzer speech_analyzer;
		ofSoundPlayer mySound;

		bool drawNext = false;
		int flashcard_list_index = -1;
		vector<string> flashcard_list = vector<string>();
		
		string user_speech;

	public:
		void setup();
		void update();
		void draw();

		// Populates the list of flashcards with desired words
		void setFlashcardList();
		// Draws the next card in the list of flashcards
		void drawNextCard();
		// Returns true if the user's pronunciation is correct. False otherwise
		bool isCorrect();

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