#pragma once
#include "ofMain.h"
#include <stdio.h>
#include "SpeechAnalyzer.h"

#define AUDIO_FILEPATH "C:\\Users\\danie\\Downloads\\preamble10.wav"

class ofApp: public ofBaseApp {
public:
	ofApp() = default;
    void setup() override;
    void draw() override;
};