#include "AppLogNormalizer.h"

int main (int argc, char* argv[]){


	if (argc != 3){
		std::cout << "Wrong number of parameters." << std::endl;
		std::cout << "Usage: AppLogNormalizer <name> <destination>" << std::endl;
		return -1;
	}


	AppLogNormalizer appLogNormalizer(argv[1],argv[2]);
	appLogNormalizer.run();

}




