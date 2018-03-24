
#include "SystemLogNormalizer.h"

int main (int argc, char* argv[]){


	if (argc != 3){
		std::cout << "Wrong number of parameters." << std::endl;
		std::cout << "Usage: SystemLogNormalizer <name> <destination>" << std::endl;
		return -1;
	}


	SystemLogNormalizer systemLogNormalizer(argv[1],argv[2]);
	systemLogNormalizer.run();

}







