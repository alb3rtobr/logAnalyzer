

#ifndef INCLUDE_APPLOGNORMALIZER_H_
#define INCLUDE_APPLOGNORMALIZER_H_

#include <string>
#include "RabbitMQSenderPipe.h"
#include "RabbitMQReceiverPipe.h"
#include "LogFilter.h"

class AppLogNormalizer : public LogFilter {

public:
	AppLogNormalizer(const std::string& name, const std::string& destination);

	~AppLogNormalizer();

	void run();

protected:

private:

	bool verifyLogMessage(const LogMessage& logMessage);

	std::string extractComponent(const std::string& rawLog);

	std::string extractSeverity(const std::string& rawLog);

	std::string extractLogText(const std::string& rawLog);

};



#endif /* INCLUDE_APPLOGNORMALIZER_H_ */
