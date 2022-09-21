#include "ImageInput.h"


ImageInput::ImageInput() {

}

void ImageInput::setup() {

	smallFont.load("rainyhearts.ttf", 22);
	photoButton.load("photo.png");
	buttonRect.set(ofGetWidth() / 2 - 25, ofGetHeight() - 100, 50, 50);

	uploadImage = "Please upload an image of yourself so that\nwe can verify that you are a human";

	camWidth = 640;  // try to grab at this size.
	camHeight = 480;

	//get back a list of devices.
	vector<ofVideoDevice> devices = vidGrabber.listDevices();

	for (size_t i = 0; i < devices.size(); i++) {
		if (devices[i].bAvailable) {
			//log the device
			ofLogNotice() << devices[i].id << ": " << devices[i].deviceName;
		}
		else {
			//log the device and note it as unavailable
			ofLogNotice() << devices[i].id << ": " << devices[i].deviceName << " - unavailable ";
		}
	}

	vidGrabber.setDeviceID(0);
	vidGrabber.setDesiredFrameRate(30);

	ofSetVerticalSync(true);

	vidGrabber.setup(camWidth, camHeight);

}




void ImageInput::update() {
	
	vidGrabber.update();



}


void ImageInput::draw() {
	
	cout << "the video is running";

	ofBackground(0);


	ofSetColor(255);

	ofDrawRectangle(buttonRect);

	smallFont.drawString(uploadImage, ofGetWidth() / 10, ofGetHeight() / 10);


	ofSetColor(255, 255, 255, 255);

	vidGrabber.draw(192, ofGetHeight()/5);


	//ofFill();
	//ofDrawRectangle(buttonRect);

	photoButton.draw(ofGetWidth() / 2 - 25, ofGetHeight() - 100, 50, 50);
}

void ImageInput::mousePressed(int x, int y, int button) {
	
	

	}
