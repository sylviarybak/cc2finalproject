#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup() {


	middleFont.load("rainyhearts.ttf", 26);
	smallFont.load("rainyhearts.ttf", 22);
	photoButton.load("photo.png");


	moth1.load("moth1.png");


	start = "Before we start, please verify that you are not a robot";
	iAmNot = "I am not a robot";
	somethingWrong = "Something went wrong. Please do another test to prove you are not a robot";
	Continue = "Continue";

	frame.set(ofGetWidth() / 2 - 150, ofGetHeight() / 2 - 50, 300, 80);
	checkbox.set(ofGetWidth() / 2 + 100, ofGetHeight() / 2 - 20, 20, 20);
	checkboxFill.set(ofGetWidth() / 2 + 100, ofGetHeight() / 2 - 20, 20, 20);


	ContinueBox.set(ofGetWidth() / 2 - 70, ofGetHeight() / 2 + 180, 140, 50);
	


	buttonRect.set(ofGetWidth() / 2 - 25, ofGetHeight() - 100, 50, 50);

	doneRec.set(ofGetWidth() / 2 - 25, ofGetHeight() - 150, 80, 50);

	yesAudio.set(ofGetWidth() / 2 - 150, ofGetHeight() / 2 + 100, 90, 50);

	captchaRec.set(ofGetWidth() / 2 - 260, ofGetHeight() / 2 - 160, 520, 320);


	runRandomizer.setup();
	runAudioOutput.setup();

	
}

//--------------------------------------------------------------
void ofApp::update(){

	runRandomizer.update();
	runAudioInput.update();
	runAudioOutput.update();


}

//--------------------------------------------------------------
void ofApp::draw() {
	ofBackground(0);


	ofFill();
	ofSetColor(220, 220, 220);
	ofDrawRectangle(frame);


	ofNoFill();
	ofSetColor(100);
	ofDrawRectangle(checkbox);

	ofNoFill();
	ofSetColor(0);
	ofDrawRectangle(yesAudio);

	ofSetColor(255);

	middleFont.drawString(start, ofGetWidth() / 8, ofGetHeight() / 5);

	ofSetColor(0);

	smallFont.drawString(iAmNot, ofGetWidth() / 2.6, ofGetHeight() / 2 - 2);

	//fills in checkbox and modifies the text 
	if ((mouseX > checkbox.x && mouseX < checkbox.x + checkbox.width) && (mouseY > checkbox.y && mouseY < checkbox.y + checkbox.height)) {
		//I'm over a rectangle  
		ofFill();
		ofDrawRectangle(checkboxFill);
		ofSetColor(0);
		iAmNot = "I am not a human";

		

	}

	else {
		iAmNot = "I am not a robot";
		

	}

	//if checkbox is clicked then it moves on to the next screen
	if (checkboxClicked) {

		ofBackground(0);

		ofSetColor(255);
		smallFont.drawString(somethingWrong, ofGetWidth() / 10 - 30, ofGetHeight() / 5);

		ofFill();
		ofSetColor(255);

		ofDrawRectangle(ContinueBox);

		ofSetColor(0);
		smallFont.drawString(Continue, ofGetWidth() / 2 - 50, ofGetHeight() / 2 + 210);
		

	}



	if (continueClicked) {


		if (oneTimeOnly == true) {
			runRandomizer.vectorCheck(randomNr);

		oneTimeOnly = false;
			
		}

		runRandomizer.draw();
		

	}

	else {

		randomNr = runRandomizer.runSelection();

	}

	
	if (photoButtonClick) {

		ofBackground(0);

		ofSetColor(255);
		smallFont.drawString(somethingWrong, ofGetWidth() / 10 - 30, ofGetHeight() / 5);

		ofFill();
		ofSetColor(255);

		ofDrawRectangle(ContinueBox);

		ofSetColor(0);
		smallFont.drawString(Continue, ofGetWidth() / 2 - 50, ofGetHeight() / 2 + 210);


		oneTimeOnly = true;
	}


	if (doneRecClick) {

	 
		runAudioOutput.draw();


	}


	if (yesAudioClick) {
		ofBackground(0);

		ofSetColor(255);
		smallFont.drawString(somethingWrong, ofGetWidth() / 10 - 30, ofGetHeight() / 5);

		ofFill();
		ofSetColor(255);

		ofDrawRectangle(ContinueBox);

		ofSetColor(0);
		smallFont.drawString(Continue, ofGetWidth() / 2 - 50, ofGetHeight() / 2 + 210);

		oneTimeOnly = true;
	}

	if (captchaRecClick) {
		ofBackground(0);

		ofSetColor(255);
		smallFont.drawString(somethingWrong, ofGetWidth() / 10 - 30, ofGetHeight() / 5);

		ofFill();
		ofSetColor(255);

		ofDrawRectangle(ContinueBox);

		ofSetColor(0);
		smallFont.drawString(Continue, ofGetWidth() / 2 - 50, ofGetHeight() / 2 + 210);

		oneTimeOnly = true;
	}


	if (doneRecClick) {


		runAudioOutput.draw();


	}

}


//--------------------------------------------------------------

void ofApp::keyPressed(int key){


}


//--------------------------------------------------------------
void ofApp::keyReleased(int key){

}

//--------------------------------------------------------------
void ofApp::mouseMoved(int x, int y ){

}

//--------------------------------------------------------------
void ofApp::mouseDragged(int x, int y, int button){

}

//--------------------------------------------------------------
void ofApp::mousePressed(int x, int y, int button){

	photoButtonClick = buttonRect.inside(x, y);

	checkboxClicked = checkbox.inside(x, y);

	continueClicked = ContinueBox.inside(x, y);

	doneRecClick = doneRec.inside(x, y);

	yesAudioClick = yesAudio.inside(x, y);

	captchaRecClick = captchaRec.inside(x, y);
}

//--------------------------------------------------------------
void ofApp::mouseReleased(int x, int y, int button){


}

//--------------------------------------------------------------
void ofApp::mouseEntered(int x, int y){

}

//--------------------------------------------------------------
void ofApp::mouseExited(int x, int y){

}

//--------------------------------------------------------------
void ofApp::windowResized(int w, int h){

}

//--------------------------------------------------------------
void ofApp::gotMessage(ofMessage msg){

}

//--------------------------------------------------------------
void ofApp::dragEvent(ofDragInfo dragInfo){ 

}

