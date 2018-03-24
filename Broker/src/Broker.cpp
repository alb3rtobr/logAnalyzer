
#include <iostream>
#include <string>
#include "Broker.h"

Broker::Broker(const std::string& name, const std::string& destination)
: name_(name)
, destination_(destination)
, receiverPipe_(name)
, senderPipe_(destination) {
}

void Broker::run(){

	std::cout << "#### BROKER " << name_ << " sending to " << destination_ << " ####\n" << std::endl;
	while(1){
		std::string msg(receiverPipe_.read());
		std::cout << msg << std::endl;
		senderPipe_.write(msg);
		std::cout << "\n----------------------\n" << std::endl;
	}

}
