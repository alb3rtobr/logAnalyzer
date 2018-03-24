
#include "RabbitMQSenderPipe.h"
#include <string>
#include <iostream>
#include <sstream>
#include "LogGenerator.h"

int main(int argc, char* argv[]){

	if (argc != 3){
		std::cout << "Wrong number of parameters." << std::endl;
		std::cout << "Usage: logGenerator <number of logs> <destination>" << std::endl;
	}

	std::istringstream ss(argv[1]);
	int numberOfLogs;
	ss >> numberOfLogs;
	RabbitMQSenderPipe senderPipe(argv[2]);
	LogGenerator logGenerator;

	std::cout << "#### LogGenerator ####" << std::endl;
	std::cout << "This tool simulates apps and systems sending logs." << std::endl;
	std::cout << "Press enter for generating a new log message.\n" << std::endl;
	while (numberOfLogs > 0){
		std::cin.get();
		std::string msg(logGenerator.generateRandomLog());
		std::cout << "Sending: " << msg <<std::endl;
		senderPipe.write(msg);
		numberOfLogs--;
	}

}

