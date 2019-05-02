# Speech Recognition Flashcards

Speech Recognition Flashcards is an openFrameworks desktop application that allows users to input a list of English words and practice pronuncing them. If the user pronounces a word incorrectly, the program will speak the word back to the user with the correct pronunciation.

This application currently only works with English words (learning English).

<h4> Dependencies </h4>
The only dependency this project requires is the Microsoft Speech APIs. Instructions of installation can be found here: https://docs.microsoft.com/en-us/azure/cognitive-services/speech-service/quickstart-text-to-speech-cpp-windows

<h4> Steps to run: </h4>

1. Download openFrameworks: (https://openframeworks.cc/download/)

2. Clone this repository

3. Follow the instructions on the link above (under "Dependencies") for downloading the Microsoft Speech Services add-ons.

4. Run the application by pressing "Local Windows Debugger" on Visual Studio (or equivalent XCode or other IDE button).
Enjoy!

<h5> Tests: </h5>
Unfortunately, it's difficult to test all the capabilities of this app since a lot of it involves the GUI. There are a few tests in the "test" folder, and a screenshot of FlashcardListTest.cpp passing all its tests, but that's it. If I were to further expand on this project, I would look into more accurate testing.


    
* sorry the links aren't in correct README style, for some reason it doesn't work even when I do the [correct format] (https://www.google.com/)
