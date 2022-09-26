#include "AudioInput.h"


//--------------------------------------------------------------
void AudioInput::setup() {

	auto inDevices = ofxSoundUtils::getInputSoundDevices();
	auto outDevices = ofxSoundUtils::getOutputSoundDevices();
	output.setOutputStream(stream);


	smallFont.load("rainyhearts.ttf", 22);
	ofSetVerticalSync(true);
	stream.setup(2, 2, 44100, 256, 1);

	wave.setup(256, 250, ofGetWidth()/2, ofGetHeight()/4);

	stream.setInput(input);
	stream.setOutput(output);

	input.connectTo(wave).connectTo(output);

	elapsedTime = ofGetElapsedTimeMillis(); // saves the elapsed time up until now


	recordAudio = "We will ask you to make a brief recording";
	recordAudio2 = "to verify that you are indeed a human";
	pleaseSay = "Please say * I am not a robot * into your microphone";
	recordingInProgress = "Recording";
	done = "Done";

	doneRec.set(ofGetWidth() / 2 - 25, ofGetHeight() - 150, 80, 50);

	player.load("notarobot.mp3");

	runAudioOutput.setup();
	

}

//--------------------------------------------------------------
void AudioInput::update() {

	ofSoundUpdate();

	
	runAudioOutput.update();

}

//--------------------------------------------------------------
void AudioInput::draw() {

	ofBackground(0);

	
	
	
	ofSetColor(255);

	// Removes the elapsed time up until this point, so that the the count reset

	if ((ofGetElapsedTimeMillis() - elapsedTime) > 6000) {
		
		smallFont.drawStringCentered(pleaseSay, ofGetWidth() / 2, ofGetHeight() / 4);
		smallFont.drawStringCentered(recordingInProgress, ofGetWidth() / 2, (ofGetHeight() / 2) + 120);
		
		if (((ofGetElapsedTimeMillis() / 500) % 2 == 0)) {
		ofFill();
		ofSetColor(255, 0, 0);
		ofDrawCircle(ofGetWidth() / 3 + 70, (ofGetHeight() / 2) + 118, 10);

		}
		else {

			ofSetColor(0);
			ofDrawCircle(ofGetWidth() / 3 + 70, (ofGetHeight() / 2) + 118, 10);

		}

		wave.draw();

		ofFill();
		ofSetColor(255);
		ofDrawRectangle(doneRec);
		ofSetColor(0);
		smallFont.drawStringCentered(done, ofGetWidth() / 2 + 13, ofGetHeight() - 128);


	}

	else {

		smallFont.drawStringCentered(recordAudio, ofGetWidth() / 2, ofGetHeight() / 3);
		smallFont.drawStringCentered(recordAudio2, ofGetWidth() / 2, (ofGetHeight() / 3) + 44);

	}

	

	player.play();
	player.setLoop(true);




}


void AudioInput::playback() {

	ofBackground(0);

	ofRectangle r;
	r.x = 256;
	r.y = 250;
	r.width = ofGetWidth() / 2;
	r.height = 150;

	ofSetColor(255);
	r.y = r.getMaxY();
	recordedWave.draw(r);
	ofPushStyle();
	ofSetHexColor(0xffee00);
	float p = ofMap(player.getPosition(), 0, 1, r.getMinX(), r.getMaxX());
	ofSetLineWidth(2);
	ofDrawLine(p, r.getMinY(), p, r.getMaxY());
	ofPopStyle();
	


}
