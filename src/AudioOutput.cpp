#include "AudioOutput.h"

AudioOutput::AudioOutput() {



}
//--------------------------------------------------------------
void AudioOutput::setup() {

	smallFont.load("rainyhearts.ttf", 22);



	player.load(ofToDataPath("notarobot.mp3"));
	//set the following to true if you want to stream the audio data from the disk on demand instead of


	playingRecording = " * Playing Recording * ";
	isThisCorrect = "Does this sound correct?";
	YesStr = "Yes";
	NoStr = "No";


	Yes.set(ofGetWidth() / 2 + 50, ofGetHeight() /2 + 100, 90, 50);
	No.set(ofGetWidth() / 2 - 150, ofGetHeight() /2 + 100, 90, 50);


}

//--------------------------------------------------------------
void AudioOutput::update() {

	ofSoundUpdate();


}


//--------------------------------------------------------------
void AudioOutput::draw() {


	player.play();
	// set if you want to either have the player looping (playing over and over again) or not (stop once it reaches the its end).
	player.setLoop(true);


	ofBackground(0);

	ofSetColor(255);

	smallFont.drawStringCentered(isThisCorrect, ofGetWidth() / 2, ofGetHeight() / 2);
	ofFill();
	ofDrawRectangle(Yes);
	ofDrawRectangle(No);


	ofSetColor(0);
	smallFont.drawStringCentered(NoStr, ofGetWidth() / 2 + 95, ofGetHeight() /2 + 125);
	smallFont.drawStringCentered(YesStr, ofGetWidth() / 2 - 105, ofGetHeight() /2 + 125);

	Yes.set(ofGetWidth() / 2 + 50, ofGetHeight() / 2 + 100, 90, 50);
	No.set(ofGetWidth() / 2 - 150, ofGetHeight() / 2 + 100, 90, 50);


	if (((ofGetElapsedTimeMillis() / 500) % 2 == 0)) {
	
		ofSetColor(255, 255, 0);

		smallFont.drawStringCentered(playingRecording, ofGetWidth() / 2, ofGetHeight() / 5);

	}
	else {

		ofSetColor(0);
		smallFont.drawStringCentered(playingRecording, ofGetWidth() / 2, ofGetHeight() / 5);

	}





	if ((ofGetMouseX() > No.x && ofGetMouseX() < Yes.x + Yes.width) && (ofGetMouseY() > Yes.y && ofGetMouseY() < Yes.y + Yes.height)) {
		//I'm over a rectangle  
		ofSetColor(0);
		ofDrawRectangle(Yes);

	}




	


}

