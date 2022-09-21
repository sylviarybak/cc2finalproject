#pragma once

#include "ofMain.h"


class ImageInput {

public: // place public functions or variables declarations here

	void draw();
	void setup();
	void update();
	void mousePressed(int x, int y, int button);

	ofRectangle test;


	string uploadImage;

	ofTrueTypeFont smallFont;

	ofRectangle buttonRect;

	ofImage photoButton;

	bool photoButtonClick = false;

	ImageInput();  // constructor - used to initialize an object, if no properties are passed the program sets them to the default value

	ofVideoGrabber vidGrabber;
	int camWidth;
	int camHeight;

private:
};


