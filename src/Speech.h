#include <iostream>
#include <speechapi_cxx.h>

#define SUBSCRIPTION_KEY "6a80416fd0ca4d35ac24a5bac46ab109"
#define REGION "centralus"

using namespace Microsoft::CognitiveServices::Speech;

using std::cout;
using std::endl;
using std::string;
using std::getline;
using std::cin;

class SpeechTool {
	private:
		string recognized_speech;

	public:
		// Default constructor
		SpeechTool() = default;

		// Recognizes speech, speech to text
		void recognizeSpeech();
		// Repeats back correct pronuciation, text to speech
		void synthesizeSpeech(string text);

		string get_recognized_speech() { return recognized_speech; };
};