
#include "LogIdentifier.h"

int main (int argc, char* argv[]){


	if (argc != 4){
		std::cout << "Wrong number of parameters." << std::endl;
		std::cout << "Usage: LogIdentifier <name> <destination for app logs> <destination for system logs>" << std::endl;
		return -1;
	}


	LogIdentifier logIdentifier(argv[1],argv[2],argv[3]); //logIdentifier
	logIdentifier.run();

}
