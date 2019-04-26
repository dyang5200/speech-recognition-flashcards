// Refer to the README.md in the example's root folder for more information on usage

#pragma once

#include "ofMain.h"
#include <vector>
#include <string>

using std::vector;
using std::string;

class ofApp : public ofBaseApp{
	
	public:

		ofSoundPlayer mySound;
		ofFbo fbo;

		bool drawNext = false;
		int count = -1;
		vector<string> flashcard_list = vector<string>();

		void setup();
		void update();
		void draw();
		
		void setFlashcardList();
		void drawNextCard();
		void keyPressed(int key);
		void keyReleased(int key);
		void mouseMoved(int x, int y );
		void mouseDragged(int x, int y, int button);
		void mousePressed(int x, int y, int button);
		void mouseReleased(int x, int y, int button);
		void mouseEntered(int x, int y);
		void mouseExited(int x, int y);
		void windowResized(int w, int h);
		void dragEvent(ofDragInfo dragInfo);
		void gotMessage(ofMessage msg);
};
	
