#include "ofApp.h"
#include <stdio.h>
#include <curl/curl.h>
#include <iostream>
#include <string>

// Saves json as a string
size_t CurlWrite_CallbackFunc_String(void* contents, size_t size, size_t nmemb, std::string* s) {
	size_t newLength = size * nmemb;
	try {
		s->append((char*)contents, newLength);
	}
	catch (std::bad_alloc & e) {
		//handle memory problem
		return 0;
	}
}

std::string SendCurlRequests(CURL *curl, std::string audio_as_str, std::string read_output) {
	if (curl) {
		curl_easy_setopt(curl, CURLOPT_CUSTOMREQUEST, "POST");
		curl_easy_setopt(curl, CURLOPT_URL, "https://centralus.stt.speech.microsoft.com/speech/recognition/conversation/cognitiveservices/v1?language=en-US&format=detailed");

		struct curl_slist* headers = NULL;
		headers = curl_slist_append(headers, "Postman-Token: 8256ce1b-92fd-41fc-aedb-0ff21c688bf6");
		headers = curl_slist_append(headers, "cache-control: no-cache");
		headers = curl_slist_append(headers, "Expect: 200-ok");
		headers = curl_slist_append(headers, "Host: westus.stt.speech.microsoft.com");
		headers = curl_slist_append(headers, "Ocp-Apim-Subscription-Key: 6a80416fd0ca4d35ac24a5bac46ab109");
		headers = curl_slist_append(headers, "Accept: application/json;text/xml");
		headers = curl_slist_append(headers, "Content-Type: audio/wav; codecs=audio/pcm; samplerate=16000");

		curl_easy_setopt(curl, CURLOPT_HTTPHEADER, headers);

		curl_easy_setopt(curl, CURLOPT_POSTFIELDS, read_output.c_str());
		curl_easy_setopt(curl, CURLOPT_POSTFIELDSIZE, read_output.length() + 1);

		curl_easy_setopt(curl, CURLOPT_SSL_VERIFYPEER, 0L); //only for https
		curl_easy_setopt(curl, CURLOPT_SSL_VERIFYHOST, 0L); //only for https
		curl_easy_setopt(curl, CURLOPT_WRITEFUNCTION, CurlWrite_CallbackFunc_String);
		curl_easy_setopt(curl, CURLOPT_WRITEDATA, &audio_as_str);
		curl_easy_setopt(curl, CURLOPT_VERBOSE, 1L);

		CURLcode ret = curl_easy_perform(curl);
	}

	return audio_as_str;
}

std::string ReadFile(std::string file_name, CURL* curl) {
	std::string audio_as_str;

	ifstream input_file(file_name, ios::binary);

	if (input_file.is_open()) {
		// Read file
		std::string read_output((std::istreambuf_iterator<char>(input_file)), (
			std::istreambuf_iterator<char>()));

		audio_as_str = SendCurlRequests(curl, audio_as_str, read_output);
	}
	else {
		std::cout << "Unable to open audio file." << endl;
	}

	return audio_as_str;
}

void ofApp::setup() {
	CURL* curl = curl_easy_init();

	std::string audio_as_str = ReadFile("C:\\Users\\danie\\Downloads\\gettysburg.wav", curl);

	/* always cleanup */
	curl_easy_cleanup(curl);

	std::cout << audio_as_str << endl;
	std::cout << "Program finished!" << endl;
}

void ofApp::draw()
{
    ofBackgroundGradient(ofColor::white, ofColor::black);

    ofDrawBitmapStringHighlight("See console for output.", ofPoint(30, 30));
}
