
#pragma once

#include "ofMain.h"
#include "Captcha.h"
#include "AudioInput.h"
#include "ImageInput.h"


class Randomizer {

public: // place public functions or variables declarations here


	void draw();
	void setup();
	void update();
	void options();
	void vectorCheck(float runSelector);
	void runAgain();

	float randomNum();
	float runSelection();
	

	Captcha runCaptcha;
	AudioInput runAudioInput;
	ImageInput runImageInput;


	int option;

	vector<float> randomNums;

	float rounded;

	int drawSelector;

	Randomizer();  // constructor - used to initialize an object, if no properties are passed the program sets them to the default value
	~Randomizer();


private: 
}; 

