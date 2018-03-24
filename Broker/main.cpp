
#include <iostream>
#include "Broker.h"

void printUsage(){
	std::cout << std::endl;
	std::cout << "broker <broker name> <destination name>" << std::endl;
}


int main (int argc, char* argv[]){


	if (argc != 3){
		std::cout << "Error: Wrong number of parameters." << std::endl;
		printUsage();
		return -1;
	}

	Broker broker(argv[1],argv[2]);
	broker.run();

}



