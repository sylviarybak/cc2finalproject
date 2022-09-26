#include "AudioOutput.h"


//--------------------------------------------------------------
void AudioOutput::setup() {

	ofSetLogLevel(OF_LOG_VERBOSE);
	//----- Loading sound player begin -------.
#ifdef USE_LOAD_DIALOG
	ofFileDialogResult result = ofSystemLoadDialog();
	if (result.bSuccess) {
		player.load(result.getPath());
	}
#else


	player.load(ofToDataPath("notarobot.mp3", true),
		//set the following to true if you want to stream the audio data from the disk on demand instead of
		//reading the whole file into memory. Default is false
		false);
#endif
	//----- Loading sound player end -------.

	//----- Sound stream setup begin -------.
	// the sound stream is in charge of dealing with your computers audio device.
	// lets print to the console the sound devices that can output sound.
	ofxSoundUtils::printOutputSoundDevices();

	auto outDevices = ofxSoundUtils::getOutputSoundDevices();

	// IMPORTANT!!!
	// The following line of code is where you set which audio interface to use.
	// the index is the number printed in the console inside [ ] before the interface name
	// You can use a different input and output device.

	int outDeviceIndex = 0;

	cout << ofxSoundUtils::getSoundDeviceString(outDevices[outDeviceIndex], false, true) << endl;


	ofSoundStreamSettings soundSettings;
	soundSettings.numInputChannels = 0;
	soundSettings.numOutputChannels = 2;
	soundSettings.sampleRate = player.getSoundFile().getSampleRate();
	soundSettings.bufferSize = 256;
	soundSettings.numBuffers = 1;

	stream.setup(soundSettings);

	output.setOutputStream(stream);


	// it is important to set up which object is going to deliver the audio data to the sound stream.
	// thus, we need to set the stream's output. The output object is going to be the last one of the audio signal chain, which is set up further down
	stream.setOutput(output);





}

//--------------------------------------------------------------
void AudioOutput::update() {

	ofSoundUpdate();

	


}


//--------------------------------------------------------------
void AudioOutput::draw() {



	ofBackground(0);

	player.play();

	player.connectTo(liveWave).connectTo(output);


	// set if you want to either have the player looping (playing over and over again) or not (stop once it reaches the its end).
	player.setLoop(true);

	ofRectangle r;
	r.x = 256;
	r.y = 250;
	r.width = ofGetWidth() / 2;
	r.height = 150;

	ofSetColor(255);

	liveWave.draw(r);

		r.y = r.getMaxY();
		recordedWave.draw(r);
		ofPushStyle();
		ofSetHexColor(0xffee00);
		float p = ofMap(player.getPosition(), 0, 1, r.getMinX(), r.getMaxX());
		ofSetLineWidth(2);
		ofDrawLine(p, r.getMinY(), p, r.getMaxY());
		ofPopStyle();



}

