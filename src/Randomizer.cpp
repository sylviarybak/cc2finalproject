#include "Randomizer.h"

Randomizer::Randomizer(){
	
}

void Randomizer::setup(){

	runImageInput.setup();

}


void Randomizer::update() {

	runImageInput.update();

}


void Randomizer::draw() {
	
	float rounded = 3.0;


	/*float rounded = roundf(randomNr);*/

	/*string num_str = to_string(rounded);*/

	if (rounded == 1) {

		runCaptcha.draw();
		randomNums.push_back(rounded);


	}

	else if (rounded == 2) {

		runAudioInput.draw();
		randomNums.push_back(rounded);

	}

	else if (rounded == 3) {

		//for (int i = 0; i < randomNums.size(); i++) {

		//	if (std::count(randomNums.begin(), randomNums.end(), 3.0)) {
			//	cout << "Element found";


		//	}
		//	else {

		runImageInput.draw();

		randomNums.push_back(rounded);

		//	}
		//}

	}
	else if (rounded == 4) {

		runTuringQuestion.draw();
		randomNums.push_back(rounded);

	}
	
	}





Randomizer::~Randomizer()
{

	//std::cout << " RandomizerStopped " << std::endl;
}


