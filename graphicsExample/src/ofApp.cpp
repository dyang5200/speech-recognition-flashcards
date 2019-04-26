// Refer to the README.md in the example's root folder for more information on usage

#include "ofApp.h"


//--------------------------------------------------------------
void ofApp::setup() {
	//mySound.load("aahhh.wav");
	//mySound.play();

	fbo.allocate(ofGetWidth(), ofGetHeight(), GL_RGBA, 8);
	fbo.begin();
	ofClear(255, 255, 255, 0);
	fbo.end();

	//counter = 0;
	//ofSetCircleResolution(50);
	//ofBackground(255,255,255);
	//bSmooth = false;

	//ofSetFrameRate(60); // if vertical sync is off, we can go a bit fast... this caps the framerate at 60fps.
}

//--------------------------------------------------------------
void ofApp::update(){
	// update event slowly increments the counter variable
	counter = counter + 0.033f;
}

//--------------------------------------------------------------
void ofApp::draw(){

	////--------------------------- circles
	////let's draw a circle:
	//ofSetColor(255,130,0);
	//float radius = 50 + 10 * sin(counter);
	//ofFill();		// draw "filled shapes"
	//ofDrawCircle(100,400,radius);

	//// now just an outline
	//ofNoFill();
	//ofSetHexColor(0xCCCCCC);
	//ofDrawCircle(100,400,80);

	// use the bitMap type
	// note, this can be slow on some graphics cards
	// because it is using glDrawPixels which varies in
	// speed from system to system.  try using ofTrueTypeFont
	// if this bitMap type slows you down.
	//ofSetHexColor(0x000000);
	//ofDrawBitmapString("circle", 75,500);


	//--------------------------- rectangles
	//ofFill();
	//for (int i = 0; i < 200; i++){
	//	ofSetColor((int)ofRandom(0,255),(int)ofRandom(0,255),(int)ofRandom(0,255));
	//	ofDrawRectangle(ofRandom(250,350),ofRandom(350,450),ofRandom(10,20),ofRandom(10,20));
	//}
	//ofSetHexColor(0x000000);
	//ofDrawBitmapString("rectangles", 275,500);

	//---------------------------  transparency

	ofSetHexColor(0xAFEEEE);
	ofDrawRectangle(100, 125, 800, 500);
	ofSetHexColor(0x000000);
	ofDrawBitmapString("INITIALLLL TEXT", 400, 390);
	ofDrawTriangle(100, 360, 100, 400, 75, 380);
	ofDrawTriangle(900, 360, 925, 380, 900, 400);

	//if (mouseReleased(4, 4, 3) == true) {
	//	ofClear(255);
	//	ofSetHexColor(0xAFEEEE);
	//	ofDrawRectangle(100, 125, 800, 500);
	//	ofSetHexColor(0x000000);
	//	ofDrawBitmapString("CHANGED TEXT", 400, 390);
	//	ofDrawTriangle(100, 360, 100, 400, 75, 380);
	//	ofDrawTriangle(900, 360, 925, 380, 900, 400);
	//}



	// alpha is usually turned off - for speed puposes.  let's turn it on!
	//ofEnableAlphaBlending();
	//ofSetColor(255,0,0,127);   // red, 50% transparent
	//ofDrawRectangle(450,430,100,33);
	//ofSetColor(255,0,0,(int)(counter * 10.0f) % 255);   // red, variable transparent
	//ofDrawRectangle(450,370,100,33);
	//ofDisableAlphaBlending();

	//---------------------------  lines
	// a bunch of red lines, make them smooth if the flag is set

	//ofSetHexColor(0xFF0000);
	//for (int i = 0; i < 20; i++){
	//	ofDrawLine(600,300 + (i*5),800, 250 + (i*10));
	//}

	//ofSetHexColor(0x000000);
	//ofDrawBitmapString("lines\npress 's' to toggle smoothness", 600,500);

}


//--------------------------------------------------------------
void ofApp::keyPressed  (int key){
	// Background turns green if correct, red if incorrect
	if (key == 'o') {
		ofSetBackgroundColor(99, 242, 109);
	} else if (key == 'x') {
		ofSetBackgroundColor(253, 38, 38);
	}
}

//--------------------------------------------------------------
void ofApp::keyReleased  (int key){

}

//--------------------------------------------------------------
void ofApp::mouseMoved(int x, int y ){

}

//--------------------------------------------------------------
void ofApp::mouseDragged(int x, int y, int button){
}

//--------------------------------------------------------------
void ofApp::mousePressed(int x, int y, int button){

}

//--------------------------------------------------------------
void ofApp::mouseReleased(int x, int y, int button){

}

//--------------------------------------------------------------
void ofApp::mouseEntered(int x, int y){

}

//--------------------------------------------------------------
void ofApp::mouseExited(int x, int y){

}

//--------------------------------------------------------------
void ofApp::windowResized(int w, int h){

}

//--------------------------------------------------------------
void ofApp::gotMessage(ofMessage msg){

}

//--------------------------------------------------------------
void ofApp::dragEvent(ofDragInfo dragInfo){ 

}
