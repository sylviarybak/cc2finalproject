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


		//if (std::count(randomNums.begin(), randomNums.end(), 0.0)) { // checks if its in the vector

			randomNums.push_back(randomNum());
			return 0;

		//}


	}

	else if (randomNum() == 1) {
		
		randomNums.push_back(randomNum());
		return 1;


	}

	else if (randomNum() == 2) {

		//for (int i = 0; i < randomNums.size(); i++) { 
		randomNums.push_back(randomNum());
		return 2;
		//}

	}
	else if (randomNum() == 3) {

		randomNums.push_back(randomNum());
		return 3;


	}

	else {

		randomNums.push_back(randomNum());
		return 4;

	}


}


void Randomizer::draw(float runSelector) {



	if (runSelector== 0) {

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

	//runTuringQuestion.draw();
	
}




Randomizer::~Randomizer()
{

	//std::cout << " RandomizerStopped " << std::endl;
}


