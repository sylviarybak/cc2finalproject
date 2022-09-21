#include "Randomizer.h"

Randomizer::Randomizer(){
	
}

void Randomizer::setup(){

	runImageInput.setup(); // i have to run this here as well apparently


}


void Randomizer::update() {

	runImageInput.update();  // this too

}


void Randomizer::draw() {

	// this runs in the draw but then it runs every frame which is not cool, if i move it out to setup or smth, the camera input doesnt work, nor will any other draws

	// float rounded = 3.0; // set to this so that i can test the camera input
	randomNums.push_back(5.0); //apparently i have to push something into the vector first for it to even work

	randomNr = ofRandom(4);

	float rounded = roundf(randomNr); //this inputs the random number

	

	if (rounded == 1) {


		if (std::count(randomNums.begin(), randomNums.end(), 1.0)) { // checks if its in the vector 


			cout << "We already had this one!";


		}
		else {

			cout << "got 1";

			runCaptcha.draw();
			randomNums.push_back(rounded);

		}

	}

	else if (rounded == 2) {

		if (std::count(randomNums.begin(), randomNums.end(), 2.0)) { // checks if its in the vector 


			cout << "We already had this one!";


		}
		else {

			cout << "got 2";
			runAudioInput.draw();
			randomNums.push_back(rounded);

		}


	}

	else if (rounded == 3) {

		//for (int i = 0; i < randomNums.size(); i++) { 

		if (std::count(randomNums.begin(), randomNums.end(), 3.0)) { // checks if its in the vector 


			cout << "We already had this one!";


		}
		else {

			cout << "Video input should play now";

			runImageInput.draw(); // runs the video input

		


		}
		//}

	}
	else if (rounded == 4) {

		if (std::count(randomNums.begin(), randomNums.end(), 4.0)) { // checks if its in the vector 


			cout << "We already had this one!";


		}
		else {

			cout << "Video input should play now";

			cout << "got 4";
			runTuringQuestion.draw();
			randomNums.push_back(rounded);




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


