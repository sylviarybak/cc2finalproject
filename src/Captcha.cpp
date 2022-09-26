
#include "Captcha.h"

Captcha::Captcha() {

}

void Captcha::setup() {
	

	moth1.load("moth1.png");

}


void Captcha::update() {


}


void Captcha::draw() {

	ofBackground(0);

	moth1.draw(ofGetWidth() / 2 - 25, ofGetHeight() /2, 200, 200);


}
