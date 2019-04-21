#pragma once
#define CATCH_CONFIG_MAIN
#include "catch.hpp"
//#include "C:\Users\danie\of_v0.10.1_vs2017_release\libs\openFrameworks\ofMain.h"
#include "../final_project/src/SpeechAnalyzer.h"
#include <fstream>
#include <string>
using std::ifstream;
using std::string;

SpeechAnalyzer speech_analyzer;

TEST_CASE("Test Working") {
	REQUIRE(1 == 1);
}

//TEST_CASE("Tests ReadFile Valid File") {
//	ifstream input_file("C:\\Users\\danie\\Downloads\\gettysburg.wav", ios::binary);
//	REQUIRE(input_file.is_open());
//}
//
//TEST_CASE("Tests ReadFile Invalid File") {
//	ifstream input_file;
//	input_file.open("thxpatrick.txt");
//	REQUIRE_FALSE(input_file.is_open());
//}
//
//TEST_CASE("Tests audio json Recognition Status") {
//	std::string audio_json = speech_analyzer.AnalyzeSpeech("C:\\Users\\danie\\Downloads\\preamble10.wav");
//	ofxJSONElement audio_as_json;
//	bool success = audio_as_json.parse(audio_json);
//	REQUIRE(audio_as_json["RecognitionStatus"].asString() == "Success");
//}
//
//TEST_CASE("Tests audio json Offset") {
//	std::string audio_json = speech_analyzer.AnalyzeSpeech("C:\\Users\\danie\\Downloads\\preamble10.wav");
//	ofxJSONElement audio_as_json;
//	bool success = audio_as_json.parse(audio_json);
//	REQUIRE(audio_as_json["Offset"].asInt() == 3100000);
//}
//
//TEST_CASE("Tests Analyze Speech") {
//	std::string speech = speech_analyzer.AnalyzeSpeech("C:\\Users\\danie\\Downloads\\preamble10.wav");
//	REQUIRE(speech == "we the people of the united states in order to form a more perfect union establish justice insure domestic tranquility provide for the common defense");
//}