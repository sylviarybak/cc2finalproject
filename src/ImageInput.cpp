#include "ImageInput.h"


ImageInput::ImageInput() {

}

void ImageInput::setup() {

	smallFont.load("rainyhearts.ttf", 22);
	videofont.load("rainyhearts.ttf", 10);
	photoButton.load("photo.png");
	buttonRect.set(ofGetWidth() / 2 - 25, ofGetHeight() - 100, 50, 50);
	videoRect.set(192, ofGetHeight() / 5, 650, 490);
	robotImage.load("robot.png");

	uploadImage = "Please upload an image of yourself so that\nwe can verify that you are a human";

	camWidth = 640;  // try to grab at this size.
	camHeight = 480;

	elapsedTime = ofGetElapsedTimeMillis();

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

	vidGrabber.setVerbose(true);
	ofEnableAlphaBlending();

	asciiCharacters = string("  ..,,,'''``--_:;^^**""=+<>iv%&xclrs)/){}I?!][1taeo7zjLunT#@JCwfy325Fp6mqSghVd4EgXPGZbYkOA8U$KHDBWNMR0Q");

}




void ImageInput::update() {
	
	vidGrabber.update();



}


void ImageInput::draw() {
	
	

	ofBackground(0);

	ofSetColor(0);

	ofDrawRectangle(buttonRect);

	ofSetColor(255);

	smallFont.drawString(uploadImage, ofGetWidth() / 10, ofGetHeight() / 10);


	ofSetColor(255, 255, 255, 255);


	vidGrabber.draw(192, ofGetHeight() / 5);
	


	//ofFill();
	//ofDrawRectangle(buttonRect);

	photoButton.draw(ofGetWidth() / 2 - 25, ofGetHeight() - 100, 50, 50);




	if ((ofGetMouseX() > videoRect.x && ofGetMouseX() < videoRect.x + videoRect.width) && (ofGetMouseY() > videoRect.y && ofGetMouseY() < videoRect.y + videoRect.height)
	&& ((ofGetElapsedTimeMillis() - elapsedTime) > 4000)) {

	ofSetColor(0);
	ofFill();
	ofDrawRectangle(192, ofGetHeight() / 5, 650, 490);

	ofPixelsRef pixelsRef = vidGrabber.getPixels();
	ofSetColor(255);

	for (int i = 0; i < camWidth; i += 7) {

		for (int j = 0; j < camHeight; j += 9) {


			float lightness = pixelsRef.getColor(i, j).getLightness();
			int character = powf(ofMap(lightness, 0, 255, 0, 1), 2.5) * asciiCharacters.size();

			videofont.drawString(ofToString(asciiCharacters[character]), i + 192, j + ofGetHeight() / 5 + 15);


	}



	}
	}

	if ((ofGetMouseX() > buttonRect.x && ofGetMouseX() < buttonRect.x + buttonRect.width) && (ofGetMouseY() > buttonRect.y && ofGetMouseY() < buttonRect.y + buttonRect.height)) {
 


	ofSetColor(255, 255, 255, 255);
	robotImage.draw(192, ofGetHeight() / 5, 640, 480);

	ofPixelsRef pixelsRef = vidGrabber.getPixels();

	ofSetColor(255, 255, 255, 50);


	for (int i = 0; i < camWidth; i += 7) {

		for (int j = 0; j < camHeight; j += 9) {


			float lightness = pixelsRef.getColor(i, j).getLightness();
			int character = powf(ofMap(lightness, 0, 255, 0, 1), 2.5) * asciiCharacters.size();

			videofont.drawString(ofToString(asciiCharacters[character]), i + 192, j + ofGetHeight() / 5 + 15);


		}

		

		}


	}
}








