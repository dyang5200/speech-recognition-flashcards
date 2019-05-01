#include "FlashcardList.h"

void FlashcardList::setFlashcards() {
	string flashcard_text;

	while (flashcard_text != QUIT_KEY) {
		cout << PROMPT << endl;
		cin >> flashcard_text;
		
		if (flashcard_text != QUIT_KEY) {
			flashcard_list.push_back(flashcard_text);
		}
	}

	// Stops current console run and begins speech-to-text and text-to-speech console run.
	cin.get();
	formatFlashcardList();
}

void FlashcardList::formatFlashcardList() {
	for (int i = 0; i < flashcard_list.size(); i++) {
		string first = flashcard_list[i].substr(0, 1);
		std::transform(first.begin(), first.end(), first.begin(), ::toupper);

		string rest = flashcard_list[i].substr(1);
		std::transform(rest.begin(), rest.end(), rest.begin(), ::tolower);

		string edited_text = first + rest;
		flashcard_list[i] = edited_text;
	}
}