#include "FlashcardList.h"

void FlashcardList::promptUser() {
	string flashcard_text;

	while (flashcard_text != "q") {
		cout << "List all the words/phrases you want to practice with.\nPress enter after each flashcard and press 'q' when finished: " << endl;
		cin >> flashcard_text;
		flashcard_list.push_back(flashcard_text);
	}

	formatFlashcardList();
}

void FlashcardList::setFlashcardList() {
	//flashcard_list.push_back("patrick");
	//flashcard_list.push_back("joseph");
	//flashcard_list.push_back("cynthia");
	//flashcard_list.push_back("kim");
	//flashcard_list.push_back("teju");
	//flashcard_list.push_back("zeba");
	//flashcard_list.push_back("aahhh");

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