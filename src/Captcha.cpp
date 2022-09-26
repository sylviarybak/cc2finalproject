
#include "Captcha.h"

Captcha::Captcha() {

}

void Captcha::setup() {
	
	smallFont.load("rainyhearts.ttf", 22);

	selectImage = "Select the image of the moth";

	moth1.load("moth1.png");
	moth2.load("moth2.png");
	moth3.load("moth3.png");
	moth4.load("moth4.png");
	moth5.load("moth5.png");
	moth6.load("moth6.png");


}


void Captcha::update() {


}


void Captcha::draw() {

	ofBackground(0);



	ofSetColor(255);

	ofRectangle(ofGetWidth() / 2 - 260, ofGetHeight() / 2 - 160, 520, 320);

	smallFont.drawStringCentered(selectImage, ofGetWidth() / 2, ofGetHeight() / 8);

	ofSetColor(255, 255, 255, 255);

	moth1.draw(ofGetWidth() / 2 - 260, ofGetHeight() / 2 - 160 , 160, 160); // first row
	moth2.draw(ofGetWidth() / 2 - 80, ofGetHeight() / 2 - 160, 160, 160);
	moth3.draw(ofGetWidth() / 2 + 100, ofGetHeight() / 2 - 160, 160, 160);

	moth4.draw(ofGetWidth() / 2 - 260, ofGetHeight() / 2 + 20, 160, 160); // second row
	moth5.draw(ofGetWidth() / 2 - 80, ofGetHeight() / 2 + 20, 160, 160);
	moth6.draw(ofGetWidth() / 2 + 100, ofGetHeight() / 2 + 20, 160, 160);



}
