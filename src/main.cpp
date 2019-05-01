#include "ofApp.h"

int main() {
	ofSetupOpenGL(1020, 768, OF_WINDOW);

    return ofRunApp(std::make_shared<ofApp>());
}
