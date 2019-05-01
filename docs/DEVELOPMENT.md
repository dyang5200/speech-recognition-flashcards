<h1> DEVELOPMENT </h1>

<h2> Week One </h2>
During Week One, I wrote my proposal. I also had to make some changes to my initial proposal. I initially planned on using ofxASR
as my Speech Recognition library, but ofxASR proved to be an archaic library that was difficult to use. As a result, I alternatively
decided to use Microsoft's Speech-to-text REST API in order to recognize speech, then use ofxJSON to parse the result.

<h2> Week Two </h2>
During Week Two, I set up CURL with Microsoft's Speech-to-text REST API. Now, I can take in an audio file, retrieve the speech, and parse the json. Finally, I print the most possible result to the console.
I still need to work on having my app take in audio that the user speaks, instead of simply an audio file.

<h2> Week Three </h2>
During Week Three, I focused on developing the flashcard GUI/graphics. I added the functionality for the GUI to turn red/green based on
the whether the user's pronunciation was right or wrong. I also added the ability for the GUI to display one flashcard to the next when
the user hits a key. My flashcards can also play sound, given an audio file, with the correct pronunciation of a word. I'm not sure to what
extent I will try to implement this extension, but it's a possibility.

<h2> Week Four </h2>
I finished my project during Week 4. I struggled intensely to find a library that allowed me to record audio and save it as a WAV file (so I can import the WAV file into the curl code I wrote last week). As a result, I switched from the curl code to a [Microsoft Speech-to-Text API](https://docs.microsoft.com/en-us/azure/cognitive-services/speech-service/quickstart-cpp-windows). This API proved to be much easier to use than curl, so I even had time to incorporate the similar [Text-to-Speech API](https://docs.microsoft.com/en-us/azure/cognitive-services/speech-service/quickstart-text-to-speech-cpp-windows) that allowed my application to repeat back the correct pronunciation of a word after the user incorrectly pronounces it. In addition, I also vastly improved the aesthetics of the GUI/UI to be more user-friendly. Finally, I wrote tests and polished up my coding style.
