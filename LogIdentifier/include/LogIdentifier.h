
#ifndef LOGIDENTIFIER_H_
#define LOGIDENTIFIER_H_

#include <string>
#include "LogFilter.h"

class LogIdentifier : public LogFilter {

public:
	LogIdentifier(const std::string& name, const std::string& appDestination,const std::string& systemDestination);

	~LogIdentifier();

	void run();

protected:

private:

	LogMessage buildLogMessageObjectFromRawLog(const std::string& message);

	bool verifyLogMessage(const LogMessage& logMessage);

	bool isAppLog(const std::string& rawLog);

	void processMessage(const std::string& message);

	static const std::string SYSTEM_LOG_DESTINATION;

	static const std::string APP_LOG_DESTINATION;

	RabbitMQSenderPipe systemLogSender_;

	RabbitMQSenderPipe appLogSender_;

};



#endif /* LOGIDENTIFIER_H_ */
