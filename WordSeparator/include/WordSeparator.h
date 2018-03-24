
#ifndef INCLUDE_WORDSEPARATOR_H_
#define INCLUDE_WORDSEPARATOR_H_

#include <iostream>
#include <string>
#include <sstream>

#include "RabbitMQSenderPipe.h"
#include "RabbitMQReceiverPipe.h"
#include "LogFilter.h"

class WordSeparator : public LogFilter {

public:
	WordSeparator(const std::string& name, const std::string& destination);

	~WordSeparator();

	void run();

protected:

private:

	bool verifyLogMessage(const LogMessage& logMessage);
};



#endif /* INCLUDE_WORDSEPARATOR_H_ */
