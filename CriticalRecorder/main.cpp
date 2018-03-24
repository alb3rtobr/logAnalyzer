
#include "CriticalRecorder.h"

int main (int argc, char* argv[]){


	if (argc != 2){
		std::cout << "Wrong number of parameters." << std::endl;
		std::cout << "Usage: CriticalRecorder <name>" << std::endl;
		return -1;
	}

	CriticalRecorder criticalRecorder(argv[1]);
	criticalRecorder.run();

}

