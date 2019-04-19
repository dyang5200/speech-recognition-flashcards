#pragma once
#include "ofMain.h"
#define AUDIO_FILEPATH "C:\\Users\\danie\\Downloads\\preamble10.wav"
#include <stdio.h>
#include <curl/curl.h>
#include <iostream>
#include <string>
#include "ofxJSON.h"
#include "ofxHTTP.h"

#include "SpeechAnalyzer.h"

class ofApp: public ofBaseApp {
public:
	ofApp() = default;
    void setup() override;
    void draw() override;
};