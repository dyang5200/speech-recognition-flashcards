#pragma once

#include "ofMain.h"
#include "ofxHTTP.h"

#define CURL_URL "https://centralus.stt.speech.microsoft.com/speech/recognition/conversation/cognitiveservices/v1?language=en-US&format=detailed"
#define POST "POST"
#define CACHE_CONTROL_HEADER "cache-control: no-cache"
#define EXPECT_HEADER "Expect: 200-ok"
#define HOST_HEADER "Host: westus.stt.speech.microsoft.com"
#define SUBSCRIPTION_KEY_HEADER "Ocp-Apim-Subscription-Key: 6a80416fd0ca4d35ac24a5bac46ab109"
#define ACCEPT_HEADER "Accept: application/json;text/xml"
#define CONTENT_TYPE_HEADER "Content-Type: audio/wav; codecs=audio/pcm; samplerate=16000"

#define FILEPATH "C:\\Users\\danie\\Downloads\\preamble10.wav"


class ofApp: public ofBaseApp {
public:
    void setup() override;
    void draw() override;
};
