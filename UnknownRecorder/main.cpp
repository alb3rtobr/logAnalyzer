
#include "UnknownRecorder.h"

int main (int argc, char* argv[]){


	if (argc != 2){
		std::cout << "Wrong number of parameters." << std::endl;
		std::cout << "Usage: UnknownRecorder <name>" << std::endl;
		return -1;
	}

	UnknownRecorder unknownRecorder(argv[1]);
	unknownRecorder.run();

}

