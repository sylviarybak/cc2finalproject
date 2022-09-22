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


void Randomizer::draw() {


	if (randomNum() == 1) {


		if (std::count(randomNums.begin(), randomNums.end(), 1.0)) { // checks if its in the vector 


			cout << "We already had this one!";


		}
		else {

			cout << "got 1";

			runCaptcha.draw();
			randomNums.push_back(randomNum());

		}

	}

	else if (randomNum() == 2) {

		if (std::count(randomNums.begin(), randomNums.end(), 2.0)) { // checks if its in the vector 


			cout << "We already had this one!";


		}
		else {

			cout << "got 2";
			runAudioInput.draw();
			randomNums.push_back(randomNum());

		}


	}

	else if (randomNum() == 3) {

		//for (int i = 0; i < randomNums.size(); i++) { 

		if (std::count(randomNums.begin(), randomNums.end(), 3.0)) { // checks if its in the vector 


			cout << "We already had this one!";


		}
		else {

			cout << "Video input should play now";

			runImageInput.draw();

			randomNums.push_back(randomNum());


		}
		//}

	}
	else if (randomNum() == 4) {

		if (std::count(randomNums.begin(), randomNums.end(), 4.0)) { // checks if its in the vector 


			cout << "We already had this one!";


		}
		else {

			cout << "Video input should play now";

			cout << "got 4";
			runTuringQuestion.draw();
			randomNums.push_back(randomNum());




		}


	}

	else {

		cout << "ok, done no more";

	}



	
	}




Randomizer::~Randomizer()
{

	//std::cout << " RandomizerStopped " << std::endl;
}


