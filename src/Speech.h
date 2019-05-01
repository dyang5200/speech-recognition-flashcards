#include <iostream>
#include <speechapi_cxx.h>

using namespace std;
using namespace Microsoft::CognitiveServices::Speech;

using std::cout;
using std::endl;

class Speech {
public:
	// Default constructor
	Speech() = default;

	void recognizeSpeech();
};