#pragma once
#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using std::vector;
using std::string;
using std::cout;
using std::endl;
using std::cin;

class FlashcardList {
    private:
        vector<string> flashcard_list = vector<string>();

    public:
		// Prompts user for the list of flashcards they want to practice with.
		void promptUser();
		// Populates the list of flashcards with desired words
		void setFlashcardList();
		// Formats the text in flashcard list so the first letter is capitalized
		void formatFlashcardList();

        vector<string> get_flashcards() { return flashcard_list; }
};