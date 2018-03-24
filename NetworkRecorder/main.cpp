
#include "NetworkRecorder.h"

int main (int argc, char* argv[]){


	if (argc != 2){
		std::cout << "Wrong number of parameters." << std::endl;
		std::cout << "Usage: NetworkRecorder <name>" << std::endl;
		return -1;
	}

	NetworkRecorder networkRecorder(argv[1]);
	networkRecorder.run();

}

