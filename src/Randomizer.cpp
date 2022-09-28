#include "Randomizer.h"

Randomizer::Randomizer(){
	
}

void Randomizer::setup(){

	runImageInput.setup(); 

	runAudioInput.setup();

	runCaptcha.setup();

	randomNums.push_back(5.0);

}


void Randomizer::update() {

	runAudioInput.update(); // i have to run this here as well apparently

	runCaptcha.update();

	runImageInput.update();  // this too

}

float Randomizer::randomNum() {



	return roundf(ofRandom(2)); //this inputs the random number
	

	
}

float Randomizer::runSelection() {


	if (randomNum() == 0) {
			
			return 0;
	}

	else if (randomNum() == 1) {
		
	
		return 1;


	}

	else if (randomNum() == 2) {

		return 2;
	

	}




}

void Randomizer::vectorCheck(float runSelector)
{



	if (runSelector == 0) {

		if (std::count(randomNums.begin(), randomNums.end(), 0.0) > 0) {  // add AND NOT IN VECTOR

	
	

		}
		else {

			drawSelector = 0;

			randomNums.push_back(runSelector);

			cout << "zero";
		}

	}

	else if (runSelector == 1) {

		if (std::count(randomNums.begin(), randomNums.end(), 1.0) > 0) {


		}
		else {

			drawSelector = 1;

			randomNums.push_back(runSelector);

			cout << "one";
		}
	}

	else if (runSelector == 2) {

		if (std::count(randomNums.begin(), randomNums.end(), 2.0) > 0) {

	



		}
		else {

			drawSelector = 2;

			randomNums.push_back(runSelector);

			cout << "two";
		}
	}

	else {

		//run again
	}



}



void Randomizer::draw() {


	if (drawSelector == 0) {

	runCaptcha.draw();
	}

	else if (drawSelector == 1) {

	runImageInput.draw();
	}

	else if (drawSelector == 2) {

	runAudioInput.draw();
	}


}

void Randomizer::runAgain() {

	// IF THE VECTOR DOES NOT CONTAIN 1 and 2 and 3 THEN RUN---- ELSE END 


	//if (oneTimeOnly == true) {
	//		runRandomizer.vectorCheck(randomNr);

	//		oneTimeOnly = false;

	//	}

	//draw();

	//else {

	//	randomNr = runRandomizer.runSelection();

	//}


}




Randomizer::~Randomizer()
{

	//std::cout << " RandomizerStopped " << std::endl;
}


