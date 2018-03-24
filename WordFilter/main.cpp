
#include "WordFilter.h"

int main (int argc, char* argv[]){


	if (argc != 3){
		std::cout << "Wrong number of parameters." << std::endl;
		std::cout << "Usage: WordFilter <name> <destination>" << std::endl;
		return -1;
	}


	WordFilter wordFilter(argv[1],argv[2]);
	wordFilter.run();

}
