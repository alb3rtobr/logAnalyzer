
#ifndef INCLUDE_SYSTEMLOGNORMALIZER_H_
#define INCLUDE_SYSTEMLOGNORMALIZER_H_

#include <string>
#include <vector>
#include "RabbitMQSenderPipe.h"
#include "RabbitMQReceiverPipe.h"
#include "LogFilter.h"

class SystemLogNormalizer : public LogFilter {

public:
	SystemLogNormalizer(const std::string& name, const std::string& destination);

	~SystemLogNormalizer();

	void run();

protected:

private:

	bool verifyLogMessage(const LogMessage& logMessage);

	std::string extractComponent(const std::string& rawLog);

	std::string extractSeverity(const std::string& rawLog);

	std::string extractLogText(const std::string& rawLog);

	static const std::vector<std::string> SEVERITY_LEVELS;

};



#endif /* INCLUDE_SYSTEMLOGNORMALIZER_H_ */
