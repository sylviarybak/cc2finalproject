
#pragma once

#include "ofMain.h"
#include "ofxSoundObjects.h"
#include "waveformDraw.h"
#include "ofxSoundRecorderObject.h"
#include "ofxCenteredTrueTypeFont.h"




class AudioInput {

public: // place public functions or variables declarations here

	void setup();
	void update();
	void draw();
	void playback();

	void keyPressed(int key);
	void keyReleased(int key);
	void mouseMoved(int x, int y);
	void mouseDragged(int x, int y, int button);
	void mousePressed(int x, int y, int button);
	void mouseReleased(int x, int y, int button);
	void windowResized(int w, int h);
	void dragEvent(ofDragInfo dragInfo);
	void gotMessage(ofMessage msg);

	waveformDraw wave;
	ofxSoundInput input;
	ofxSoundOutput output;
	ofSoundStream stream;

	ofSoundPlayer  play;

	ofxCenteredTrueTypeFont smallFont;

	float elapsedTime;

	string recordAudio;
	string recordAudio2;
	string pleaseSay;
	string recordingInProgress;
	string done;

	ofRectangle doneRec;

	ofSoundPlayer  player;
	waveformDraw liveWave, recordedWave;

	ofxSoundRecorderObject recorder;

private:
};
