#pragma once
#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

#define	QUIT_KEY "q"
#define PROMPT "List all the words/phrases you want to practice with.\nPress enter after each flashcard and press 'q' when finished: "

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
		void setFlashcards();
		// Formats the text in flashcard list so the first letter is capitalized
		void formatFlashcardList();

        vector<string> get_flashcards() { return flashcard_list; }

        void set_flashcards(vector<string> input_flashcards) { flashcard_list = input_flashcards; }
};