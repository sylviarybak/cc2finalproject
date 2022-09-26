
#pragma once

#include "ofMain.h"
#include "ofxSoundObjects.h"
#include "waveformDraw.h"
#include "ofxSoundRecorderObject.h"
#include "ofxCenteredTrueTypeFont.h"

#include "ofxSoundPlayerObject.h"
#include "ofxGui.h"
#include "SineWaveGenerator.h"

class AudioOutput {

public: // place public functions or variables declarations here
public:
	void setup();
	void update();
	void draw();

	void keyPressed(int key);
	void keyReleased(int key);
	void mouseMoved(int x, int y);
	void mouseDragged(int x, int y, int button);
	void mousePressed(int x, int y, int button);
	void mouseReleased(int x, int y, int button);
	void mouseEntered(int x, int y);
	void mouseExited(int x, int y);
	void windowResized(int w, int h);
	void dragEvent(ofDragInfo dragInfo);
	void gotMessage(ofMessage msg);


	waveformDraw liveWave, recordedWave;

	ofxSoundInput input;
	ofxSoundOutput output;
	ofSoundStream stream;
	ofxSoundMixer mixer;




	ofxSoundRecorderObject recorder;
	ofxSoundPlayerObject player;

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
