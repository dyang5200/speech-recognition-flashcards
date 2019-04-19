#pragma once
#include <stdio.h>
#include "ofMain.h"
#include <stdio.h>
#include <curl/curl.h>
#include <iostream>
#include <string>
#include "ofxJSON.h"
#include "ofxHTTP.h"

#define CURL_URL "https://centralus.stt.speech.microsoft.com/speech/recognition/conversation/cognitiveservices/v1?language=en-US&format=detailed"
#define POST "POST"
#define CACHE_CONTROL_HEADER "cache-control: no-cache"
#define EXPECT_HEADER "Expect: 200-ok"
#define HOST_HEADER "Host: westus.stt.speech.microsoft.com"
#define SUBSCRIPTION_KEY_HEADER "Ocp-Apim-Subscription-Key: 6a80416fd0ca4d35ac24a5bac46ab109"
#define ACCEPT_HEADER "Accept: application/json;text/xml"
#define CONTENT_TYPE_HEADER "Content-Type: audio/wav; codecs=audio/pcm; samplerate=16000"

using std::cout;
using std::endl;

class SpeechAnalyzer {
public: 
	// Default constructor
	SpeechAnalyzer() = default;

	// Sends curl requests to server
	std::string SendCurlRequests(CURL* curl, std::string audio_as_str, std::string read_output);

	// Reads in the audio file as a binary
	std::string ReadFile(std::string file_name);

	// Analyzes speech from an audio file
	std::string AnalyzeSpeech(std::string audio_filepath);
};

// Saves json as a string
size_t CurlWrite_CallbackFunc_String(void* contents, size_t size, size_t nmemb, std::string* s);