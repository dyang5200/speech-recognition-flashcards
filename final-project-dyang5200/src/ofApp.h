//#pragma once

#ifndef _TEST_APP
#define _TEST_APP

#include "ofMain.h"
#include "ofxSphinxASR.h"

class testApp : public ofBaseApp {

public:
	void setup();     // set up ASR engines
	void exit();
	void draw();
	void mousePressed(int x, int y, int button);  // press mouse to record
	void mouseReleased();                    // release mouse to stop record
	void audioReceived(float* input, int bufferSize, int nChannels);

private:
	ofTrueTypeFont	verdana;
	ofxASR* engine1_listenFromList;
	ofxASR* engine2_listenFromAnything;
	ofAsrEngineArgs* e;
	string result_from_engine1;
	string result_from_engine2;
};

#endif

//
//class ofApp : public ofBaseApp{
//
//	public:
//		void setup();
//		void update();
//		void draw();
//
//		void keyPressed(int key);
//		void keyReleased(int key);
//		void mouseMoved(int x, int y );
//		void mouseDragged(int x, int y, int button);
//		void mousePressed(int x, int y, int button);
//		void mouseReleased(int x, int y, int button);
//		void mouseEntered(int x, int y);
//		void mouseExited(int x, int y);
//		void windowResized(int w, int h);
//		void dragEvent(ofDragInfo dragInfo);
//		void gotMessage(ofMessage msg);
//		
//};
