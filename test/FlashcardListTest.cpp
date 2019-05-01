#define CATCH_CONFIG_MAIN
#include "catch.hpp"
#include "../src/FlashcardList.h"
#include <fstream>
#include <string>

using std::stringstream;
using std::string;

FlashcardList flashcard_list;

void setup() {
	vector<string> flashcards = vector<string>();
	flashcards.push_back("first");
	flashcards.push_back("second");
	flashcard_list.set_flashcards(flashcards);
	flashcard_list.formatFlashcardList();
}

TEST_CASE("Test FormatFlashcardList(): Empty vector") {
	vector<string> flashcards = vector<string>();
	flashcard_list.set_flashcards(flashcards);
	flashcard_list.formatFlashcardList();
	REQUIRE(flashcard_list.get_flashcards().size() == 0);
}

TEST_CASE("Test FormatFlashcardList(): Non-empty Vector, Correct Size") {
	setup();
	REQUIRE(flashcard_list.get_flashcards().size() == 2);
}

TEST_CASE("Test FormatFlashcardList(): Correct Formatting") {
	REQUIRE(flashcard_list.get_flashcards()[0] == "First");
	REQUIRE(flashcard_list.get_flashcards()[1] == "Second");
}