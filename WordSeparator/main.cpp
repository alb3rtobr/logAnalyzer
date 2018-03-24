
#include "WordSeparator.h"

int main (int argc, char* argv[]){


	if (argc != 3){
		std::cout << "Wrong number of parameters." << std::endl;
		std::cout << "Usage: WordSeparator <name> <destination>" << std::endl;
		return -1;
	}


	WordSeparator wordSeparator(argv[1],argv[2]);
	wordSeparator.run();

}
