

#ifndef INCLUDE_BROKER_H_
#define INCLUDE_BROKER_H_

#include <string>
#include "RabbitMQSenderPipe.h"
#include "RabbitMQReceiverPipe.h"

class Broker{
public:
	Broker(const std::string& name, const std::string& destination);

	void run();

protected:

private:

	std::string name_;

	std::string destination_;

	RabbitMQReceiverPipe receiverPipe_;

	RabbitMQSenderPipe senderPipe_;

};



#endif /* INCLUDE_BROKER_H_ */
