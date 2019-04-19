#include "ofApp.h"

//size_t CurlWrite_CallbackFunc_String(void* contents, size_t size, size_t nmemb, std::string* s) {
//	size_t newLength = size * nmemb;
//	try {
//		s->append((char*)contents, newLength);
//	} catch (std::bad_alloc & e) {
//		//handle memory problem
//		return 0;
//	}
//}
//
//std::string SendCurlRequests(CURL* curl, std::string audio_as_str, std::string read_output) {
//	if (curl) {
//		curl_easy_setopt(curl, CURLOPT_CUSTOMREQUEST, POST);
//		curl_easy_setopt(curl, CURLOPT_URL, CURL_URL);
//
//		struct curl_slist* headers = NULL;
//		headers = curl_slist_append(headers, CACHE_CONTROL_HEADER);
//		headers = curl_slist_append(headers, EXPECT_HEADER);
//		headers = curl_slist_append(headers, HOST_HEADER);
//		headers = curl_slist_append(headers, SUBSCRIPTION_KEY_HEADER);
//		headers = curl_slist_append(headers, ACCEPT_HEADER);
//		headers = curl_slist_append(headers, CONTENT_TYPE_HEADER);
//
//		curl_easy_setopt(curl, CURLOPT_HTTPHEADER, headers);
//
//		curl_easy_setopt(curl, CURLOPT_POSTFIELDS, read_output.c_str());
//		curl_easy_setopt(curl, CURLOPT_POSTFIELDSIZE, read_output.length() + 1);
//
//		curl_easy_setopt(curl, CURLOPT_SSL_VERIFYPEER, 0L); //only for https
//		curl_easy_setopt(curl, CURLOPT_SSL_VERIFYHOST, 0L); //only for https
//		curl_easy_setopt(curl, CURLOPT_WRITEFUNCTION, CurlWrite_CallbackFunc_String);
//		curl_easy_setopt(curl, CURLOPT_WRITEDATA, &audio_as_str);
//		curl_easy_setopt(curl, CURLOPT_VERBOSE, 1L);
//
//		CURLcode ret = curl_easy_perform(curl);
//	}
//
//	/* always cleanup */
//	curl_easy_cleanup(curl);
//
//	return audio_as_str;
//}
//
//std::string ReadFile(std::string file_name) {
//	CURL* curl = curl_easy_init();
//	std::string audio_as_str;
//	ifstream input_file(file_name, ios::binary);
//
//	if (input_file.is_open()) {
//		// Read file
//		std::string read_output((std::istreambuf_iterator<char>(input_file)), (
//			std::istreambuf_iterator<char>()));
//
//		audio_as_str = SendCurlRequests(curl, audio_as_str, read_output);
//	}
//	else {
//		std::cout << "Unable to open audio file." << endl;
//	}
//
//	cout << "audio_as string: " << audio_as_str << endl;
//	return audio_as_str;
//}
//
//std::string AnalyzeSpeech(std::string audio_filepath) {
//	std::string audio_as_str = ReadFile(audio_filepath);
//
//	//std::cout << audio_as_str << endl;
//
//	// Create new json object
//	ofxJSONElement audio_as_json;
//	bool success = audio_as_json.parse(audio_as_str);
//	cout << "SUCCESS PARSING JSON? " << success << endl << endl;
//
//	// Prints out recognized speech
//	std::string lexical = audio_as_json["NBest"][0]["Lexical"].asString();
//
//	return lexical;
//}

void ofApp::setup() {
	SpeechAnalyzer speech_analyzer;
	std::string lexical = speech_analyzer.AnalyzeSpeech(AUDIO_FILEPATH);

	cout << "Lexical: " << lexical << endl;
}

void ofApp::draw() {
    ofBackgroundGradient(ofColor::white, ofColor::black);
    ofDrawBitmapStringHighlight("See console for output.", ofPoint(30, 30));
}
