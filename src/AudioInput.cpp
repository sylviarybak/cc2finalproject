#include "AudioInput.h"

AudioInput::AudioInput(){

}

void AudioInput::setup(){
	

	ofSetLogLevel(OF_LOG_VERBOSE);

	ofxSoundUtils::printInputSoundDevices();


	auto inDevices = ofxSoundUtils::getInputSoundDevices();
	auto outDevices = ofxSoundUtils::getOutputSoundDevices();
	// IMPORTANT!!!
	// The following line of code is where you set which audio interface to use.
	// the index is the number printed in the console inside [ ] before the interface name 

	size_t inDeviceIndex = 0;
	size_t outDeviceIndex = 0;

	// Setup the sound stream.
	ofSoundStreamSettings settings;
	settings.bufferSize = 256;
	settings.numBuffers = 1;
	settings.numInputChannels = inDevices[inDeviceIndex].inputChannels;
	settings.numOutputChannels = outDevices[outDeviceIndex].outputChannels;
	settings.sampleRate = 44100;
	settings.setInDevice(inDevices[inDeviceIndex]);
	settings.setOutDevice(outDevices[outDeviceIndex]);

	stream.setup(settings);


	// link the sound stream with the ofxSoundObjects
	input.setInputStream(stream);
	output.setOutputStream(stream);

	//Set up the waveform object. The parameters passed here define the rectangle where the waveform gets drawn.


	bRecordingEnded = false;

	//we will use a mixer right before the output, just to mute out the output and avoid the nasty feedback you get otherwise. This is kind of a hack and eventually it would be unnecesary. You can add add a GUI to the mixer if you want to. Look at the mixer example.
	mixer.setMasterVolume(0);

	//start in recording mode
	setRecordingMode();





}

void AudioInput::setPlaybackMode() {
	recordingEndListener.unsubscribe();
	state = PLAYING;
	player.connectTo(liveWave).connectTo(output);
	player.play();
	cout << "SET PLAYBACK MODE" << endl;
}
//--------------------------------------------------------------
void AudioInput::setRecordingMode() {
	if (player.isPlaying()) {
		player.stop();
	}
	state = RECORDING;

	input.connectTo(liveWave).connectTo(recorder).connectTo(mixer).connectTo(output);
	recordingEndListener = recorder.recordingEndEvent.newListener(this, &AudioInput::recordingEndCallback);
	cout << "SET RECORDING MODE" << endl;
}
//--------------------------------------------------------------
void AudioInput::recordingEndCallback(string & filepath) {
	//this gets called when the recording ends.
	//NOTICE: It will get triggered from either the audio thread or the recorder's own thread (if OFX_SOUND_ENABLE_THREADED_RECORDER has been defined in ofxSoundObjectsConstants.h), which in any case are not the main thread so you should be careful about the callback function.
	cout << "recordingEndCallback" << endl;
	bRecordingEnded = true;
}
void printBuffer(const ofSoundBuffer& b, const string& name) {
	cout << name << endl;
	cout << "	size      : " << b.size() << endl;
	cout << "	numChans  : " << b.getNumChannels() << endl;
	cout << "	numFrames : " << b.getNumFrames() << endl;
	cout << "	samplerate: " << b.getSampleRate() << endl;
}


void AudioInput::update() {

	if (bRecordingEnded) {
		bRecordingEnded = false;

		//	player.load(filepath);
		player.load(recorder.getRecordedBuffer(), ofFilePath::getBaseName(recorder.getFileName()));

		printBuffer(recorder.getRecordedBuffer(), "recorder Buffer");
		printBuffer(player.getBuffer(), "Player buffer");

		recordedWave.makeMeshFromBuffer(recorder.getRecordedBuffer());

		setPlaybackMode();
	}

}


void AudioInput::draw() {
	ofBackground(0);


	stringstream ss;
	ss << ((state == RECORDING) ? "Please record yourself saying *I am not a robot* to verify your humanity" : "Is this recording correct?") << endl;
	ss << ((state == RECORDING) ? "Press the space bar to start/stop recording" : " ") << endl;
	if (state == RECORDING) {
		if (recorder.isRecording()) {
			ss << "Recording." << endl;
		}
	}

	auto textRect = bf.getBoundingBox(ss.str(), 20, 20);
	ofDrawBitmapStringHighlight(ss.str(), 20, 20);

	ofSetColor(0);

	ofRectangle r;
	r.x = 256;
	r.y = 250;
	r.width = ofGetWidth() / 2;
	r.height = 150;

	ofSetColor(255);

	liveWave.draw(r);
	if (state == PLAYING) {
		r.y = r.getMaxY();
		recordedWave.draw(r);
		ofPushStyle();
		ofSetHexColor(0xffee00);
		float p = ofMap(player.getPosition(), 0, 1, r.getMinX(), r.getMaxX());
		ofSetLineWidth(2);
		ofDrawLine(p, r.getMinY(), p, r.getMaxY());
		ofPopStyle();
	}


	if (key == ' ') {
		if (state == RECORDING) {
			if (recorder.isRecording()) {
				recorder.stopRecording();
			}
			else {
				recorder.startRecording(//first we pass the path to the file where we want to record to
					ofToDataPath(ofGetTimestampString() + ".wav", true),
					//the second argument must be true in order to keep the recorded data on the
					//computers memory so there is no need to read from disk in ordeer to playback the recently recorded sound. This is by default false.
					true
				);
			}
		}
		else {
			if (player.isPlaying()) {
				player.setPaused(true);
			}
			else {
				player.play();
			}
		}
	}
	else if (key == 'r' && state == PLAYING) {
		setRecordingMode();

}

void AudioInput::keyPressed(int key) {

	}
}