
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


	AudioOutput();

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


	ofxSoundPlayerObject player;

	string playingRecording;
	string isThisCorrect;


	string YesStr;
	string NoStr;

	ofRectangle Yes;
	ofRectangle No;

	ofxCenteredTrueTypeFont smallFont;

private:


};
