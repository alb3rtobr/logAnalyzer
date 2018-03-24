
#ifndef INCLUDE_WORDFILTER_H_
#define INCLUDE_WORDFILTER_H_

#include <iostream>
#include <string>
#include <sstream>

#include "RabbitMQSenderPipe.h"
#include "RabbitMQReceiverPipe.h"
#include "LogFilter.h"

class WordFilter : public LogFilter {

public:
	WordFilter(const std::string& name, const std::string& destination);

	~WordFilter();

	void run();

protected:

private:

	bool verifyLogMessage(const LogMessage& logMessage);
};



#endif /* INCLUDE_WORDFILTER_H_ */
