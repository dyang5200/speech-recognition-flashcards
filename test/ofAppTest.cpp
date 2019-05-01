#define CATCH_CONFIG_MAIN
#include "catch.hpp"
#include "../src/ofApp.h"
#include <string>
using std::string;

ofApp app;

vector<string> setup() {
    vector<string> flashcards = vector<string>();
	flashcards.push_back("first");
	flashcards.push_back("second");
    flashcards.push_back("third");
}

TEST_CASE("Test changeBackground(): correct") {
	REQUIRE(app.changeBackground(true) == 0x60E55B);
}

TEST_CASE("Test changeBackground(): incorrect") {
    REQUIRE(app.changeBackground(false) == 0xFF5164);
}

TEST_CASE("Test changeFlashcard(): next") {
    vector<string> flashcards = setup();
    ofApp.set_flashcards(flashcards);
    REQUIRE(app.changeFlashcard('d') == 0);
    REQUIRE(app.changeFlashcard('d') == 1);
    REQUIRE(app.changeFlashcard('d') == 2);
    REQUIRE(app.changeFlashcard('d') == 0);
    REQUIRE(app.changeFlashcard('a') == 2);
}