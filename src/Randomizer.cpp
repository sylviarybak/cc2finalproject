#include "Randomizer.h"

Randomizer::Randomizer(){
	
}

void Randomizer::setup(){

	runImageInput.setup(); // i have to run this here as well apparently
	runAudioInput.setup();


	randomNums.push_back(5.0);

}


void Randomizer::update() {

	runImageInput.update();  // this too
	runAudioInput.update();
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

void Randomizer::vectorCheck(float runSelector)
{



	if (runSelector == 0) {

		if (std::count(randomNums.begin(), randomNums.end(), 0.0) > 0) {

			cout << "we had this one";

		}
		else {

			drawSelector = 0;

			randomNums.push_back(runSelector);

			cout << "zero";
		}

	}

	else if (runSelector == 1) {

		if (std::count(randomNums.begin(), randomNums.end(), 1.0) > 0) {

			cout << "we had this one";

		}
		else {

			drawSelector = 1;

			randomNums.push_back(runSelector);

			cout << "one";
		}
	}

	else if (runSelector == 2) {

		if (std::count(randomNums.begin(), randomNums.end(), 2.0) > 0) {

			cout << "we had this one";



		}
		else {

			drawSelector = 2;

			randomNums.push_back(runSelector);

			cout << "two";
		}
	}

	else if (runSelector == 3) {

		if (std::count(randomNums.begin(), randomNums.end(), 3.0) > 0) {

			cout << "we had this one";

		}
		else {

			drawSelector = 3;

			randomNums.push_back(runSelector);

			cout << "three";
		}
	}



}



void Randomizer::draw() {

	runAudioInput.draw();

	/*if (drawSelector == 0) {

	runCaptcha.draw();
	}

	else if (drawSelector == 1) {

	runImageInput.draw();
	}

	else if (drawSelector == 2) {

	runAudioInput.draw();
	}

	else if (drawSelector == 3) {

	runTuringQuestion.draw();
	}
*/


}




Randomizer::~Randomizer()
{

	//std::cout << " RandomizerStopped " << std::endl;
}


