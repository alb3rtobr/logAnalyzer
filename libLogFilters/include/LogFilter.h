
#ifndef INCLUDE_LOGFILTER_H_
#define INCLUDE_LOGFILTER_H_

#include <iostream>

#include "RabbitMQReceiverPipe.h"
#include "RabbitMQSenderPipe.h"
#include "LogSerializer.h"

class LogFilter{

public:
	LogFilter(const std::string& name, const std::string& destination);

	virtual ~LogFilter();

	virtual void run() = 0;

protected:

	const std::string name_;

	const std::string destination_;

	RabbitMQReceiverPipe receiverPipe_;

	RabbitMQSenderPipe senderPipe_;

	LogSerializer logSerializer_;

private:

};


#endif /* INCLUDE_LOGFILTER_H_ */
