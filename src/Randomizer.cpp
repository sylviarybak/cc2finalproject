#include "Randomizer.h"

Randomizer::Randomizer(){
	
}

void Randomizer::setup(){

	runImageInput.setup(); // i have to run this here as well apparently
	randomNums.push_back(5.0); //apparently i have to push something into the vector first for it to even work

}


void Randomizer::update() {

	runImageInput.update();  // this too

}

float Randomizer::randomNum() {


	//rounded = 3.0; // set to this so that i can test the camera input

	return roundf(ofRandom(4)); //this inputs the random number
	

	
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
	else if (randomNum() == 3) {

	
		return 3;


	}



}


void Randomizer::draw(float runSelector) {


	if (runSelector == 0) {

		runCaptcha.draw();
	}

	else if (runSelector == 1) {

		runImageInput.draw();
	}

	else if (runSelector == 2) {

		runAudioInput.draw();
	}

	else if (runSelector == 3) {

		runTuringQuestion.draw();
	}


	//if (runSelector == 0) {

	//	if (std::count(randomNums.begin(), randomNums.end(), 0.0)) {

	//		cout << "we had this one";

	//	}
	//	else {
	//
	//		runCaptcha.draw();
	//
	//		randomNums.push_back(runSelector);
	//	}
	//	
	//}

	//else if (runSelector == 1) {

	//	if (std::count(randomNums.begin(), randomNums.end(), 1.0)) {

	//		cout << "we had this one";

	//	}
	//	else {

	//		runImageInput.draw();
	//	
	//		randomNums.push_back(runSelector);
	//	}
	//}

	//else if (runSelector == 2) {

	//	if (std::count(randomNums.begin(), randomNums.end(), 2.0)) {

	//		cout << "we had this one";

	//	}
	//	else {

	//		runAudioInput.draw();

	//		randomNums.push_back(runSelector);
	//	}
	//}

	//else if (runSelector == 3) {

	//	if (std::count(randomNums.begin(), randomNums.end(), 3.0)) {

	//		cout << "we had this one";

	//	}
	//	else {

	//		runTuringQuestion.draw();
	//
	//		randomNums.push_back(runSelector);
	//	}
	//}

	//runTuringQuestion.draw();
	
}




Randomizer::~Randomizer()
{

	//std::cout << " RandomizerStopped " << std::endl;
}


