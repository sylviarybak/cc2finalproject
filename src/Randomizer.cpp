#include "Randomizer.h"

Randomizer::Randomizer(){
	
}

void Randomizer::setup(){

	runImageInput.setup(); // i have to run this here as well apparently

	runAudioInput.setup();



	randomNums.push_back(5.0);

}


void Randomizer::update() {

	runAudioInput.update(); // i have to run this here as well apparently


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




}



void Randomizer::draw() {

	runCaptcha.draw();

	//if (drawSelector == 0) {

	//runCaptcha.draw();
	//}

	//else if (drawSelector == 1) {

	//runImageInput.draw();
	//}

	//else if (drawSelector == 2) {

	//runAudioInput.draw();
	//}


}




Randomizer::~Randomizer()
{

	//std::cout << " RandomizerStopped " << std::endl;
}


