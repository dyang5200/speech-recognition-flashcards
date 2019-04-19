#pragma once
#include <stdio.h>
#include <iostream>
#include <string>
#include <ofxJSON\src\ofxJSON.h>

#include "C:\Users\danie\of_v0.10.1_vs2017_release\libs\openFrameworks\ofMain.h"
#include "C:\Users\danie\of_v0.10.1_vs2017_release\addons\ofxHTTP\src\ofxHTTP.h"

#define AUDIO_FILEPATH "C:\\Users\\danie\\Downloads\\preamble10.wav"

#include "SpeechAnalyzer.h"

class ofApp: public ofBaseApp {
public:
	ofApp() = default;
    void setup() override;
    void draw() override;
};