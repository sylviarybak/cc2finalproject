#pragma once

#include "ofMain.h"
#include "ofxCenteredTrueTypeFont.h"

class Captcha {

public: // place public functions or variables declarations here

	Captcha();  // constructor - used to initialize an object, if no properties are passed the program sets them to the default value

	void setup();
	void update();
	void draw();

	ofImage moth1;
	ofImage moth2;
	ofImage moth3;
	ofImage moth4;
	ofImage moth5;
	ofImage moth6;

	ofxCenteredTrueTypeFont smallFont;
	string selectImage;

private:


};

