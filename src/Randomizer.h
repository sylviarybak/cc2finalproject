
#pragma once

#include "ofMain.h"
#include "Captcha.h"
#include "AudioInput.h"
#include "ImageInput.h"
#include "TuringQuestion.h"

class Randomizer {

public: // place public functions or variables declarations here


	void draw();
	void setup();
	void update();

	Captcha runCaptcha;
	AudioInput runAudioInput;
	ImageInput runImageInput;
	TuringQuestion runTuringQuestion;

	ofTrueTypeFont smallFont;

	vector<float> randomNums;

	float randomNr;

	void vectorCheck(); 

	Randomizer();  // constructor - used to initialize an object, if no properties are passed the program sets them to the default value
	~Randomizer();


private: 
}; 

