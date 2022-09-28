#pragma once

#include "ofMain.h"
#include "Captcha.h"
#include "AudioInput.h"
#include "ImageInput.h"
#include "Randomizer.h"
#include "AudioOutput.h"





class ofApp : public ofBaseApp{

	public:
		void setup();
		void update();
		void draw();



		void keyPressed(int key);
		void keyReleased(int key);
		void mouseMoved(int x, int y );
		void mouseDragged(int x, int y, int button);
		void mousePressed(int x, int y, int button);
		void mouseReleased(int x, int y, int button);
		void mouseEntered(int x, int y);
		void mouseExited(int x, int y);
		void windowResized(int w, int h);
		void dragEvent(ofDragInfo dragInfo);
		void gotMessage(ofMessage msg);



		ofTrueTypeFont largeFont;
		ofTrueTypeFont middleFont;
		ofTrueTypeFont smallFont; 
		
		string start; // start screen text 
		string iAmNot; // I am not a robot text
		string somethingWrong; //Something went wrong
		string Continue;
		string num_str; //just for previewing the number, delete later 

		ofRectangle frame;
		ofRectangle checkbox;
		ofRectangle checkboxFill; // elements on start screen
		ofRectangle ContinueBox;
		ofRectangle doneRec;

		bool checkboxClicked = false;

		bool continueClicked = false;

		float randomNr;

		void randomNumberGen(); // to generate a random number, which is later used to select the task

		void checkBoxClick();

		Captcha runCaptcha;
		AudioInput runAudioInput;
		ImageInput runImageInput;
		Randomizer runRandomizer;
		AudioOutput runAudioOutput;

		bool oneTimeOnly = true;


		ofRectangle buttonRect;
		ofRectangle audioRect;
		ofRectangle yesAudio;
		ofRectangle captchaRec;


		ofImage photoButton;
		ofImage moth1;


		bool photoButtonClick = false;
		bool doneRecClick = false;
		bool yesAudioClick = false;
		bool captchaRecClick = false;

		bool Record = false;

		

};
