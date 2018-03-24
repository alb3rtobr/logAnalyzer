
#ifndef INCLUDE_STANDARDRECORDER_H_
#define INCLUDE_STANDARDRECORDER_H_

#include <fstream>
#include "LogFilter.h"

class StandardRecorder : public LogFilter {

public:
	StandardRecorder(const std::string& name, const std::vector<std::string> destinationPipes);

	~StandardRecorder();

	void run();

protected:

private:

	bool verifyLogMessage(const LogMessage& logMessage);

	std::string getPipeNamesAsString();

	static const std::string OUTPUT_FILENAME;

	static const std::string DELIMITER;

	std::vector<std::string> destinationPipeNames_;

	std::vector<RabbitMQSenderPipe*> outputPipes_;
};



#endif /* INCLUDE_STANDARDRECORDER_H_ */
