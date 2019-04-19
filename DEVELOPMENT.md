<h1> DEVELOPMENT </h1>

<h2> Week One </h2>
During Week One, I wrote my proposal. I also had to make some changes to my initial proposal. I initially planned on using ofxASR
as my Speech Recognition library, but ofxASR proved to be an archaic library that was difficult to use. As a result, I alternatively
decided to use Microsoft's Speech-to-text REST API in order to recognize speech, then use ofxJSON to parse the result.

<h2> Week Two </h2>
During Week Two, I set up CURL with Microsoft's Speech-to-text REST API. Now, I can take in an audio file, retrieve the speech, and parse the json. Finally, I print the most possible result to the console.
