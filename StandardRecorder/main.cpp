
#include "StandardRecorder.h"

int main (int argc, char* argv[]){


	if (argc < 3){
		std::cout << "Wrong number of parameters." << std::endl;
		std::cout << "Usage: StandardRecorder <name> [<destination> | <destination> ...]" << std::endl;
		return -1;
	}

	std::vector<std::string> destinationPipes;
	int i=0;
	for(i=2; i<argc; i++){
		std::string token(argv[i]);
		destinationPipes.push_back(token);
	}

	StandardRecorder standardRecorder(argv[1],destinationPipes);
	standardRecorder.run();

}
