#include <iostream>
#include <speechapi_cxx.h>

#define SUBSCRIPTION_KEY "6a80416fd0ca4d35ac24a5bac46ab109"
#define REGION "centralus"

//using namespace std;
using namespace Microsoft::CognitiveServices::Speech;

using std::cout;
using std::endl;
using std::string;

class Speech {
	private:
		string recognized_speech;

	public:
		// Default constructor
		Speech() = default;

		void recognizeSpeech();

		string get_recognized_speech() { return recognized_speech; };
};