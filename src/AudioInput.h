
#pragma once

#include "ofMain.h"
#include "ofxSoundObjects.h"
#include "waveformDraw.h"
#include "ofxSoundRecorderObject.h"

class AudioInput {

public: // place public functions or variables declarations here


	void draw();
	void setup();
	void update();

	void keyPressed(int key);

	AudioInput();  // constructor - used to initialize an object, if no properties are passed the program sets them to the default value

	waveformDraw liveWave, recordedWave;

	ofxSoundInput input;
	ofxSoundOutput output;
	ofSoundStream stream;
	ofxSoundMixer mixer;


	ofxSoundRecorderObject recorder;
	ofxSoundPlayerObject player;

	string verify; 
	string spacebar; 
	string recording;
	string isthiscorrect; 
	string yes;
	string no; 

	void setPlaybackMode();
	void setRecordingMode();

	enum State {
		RECORDING,
		PLAYING
	}state;

	std::atomic<bool> bRecordingEnded;




	//this will keep a listener so we can know that the recording has ended and its resources are free so it is safe to use the recently recorded file.

	ofEventListener recordingEndListener;
	void recordingEndCallback(string & filepath);

	ofBitmapFont bf;


private: 
}; 

