
#ifndef INCLUDE_FILERECORDERFILTER_H_
#define INCLUDE_FILERECORDERFILTER_H_

#include <fstream>
#include "LogFilter.h"

class FileRecorderFilter : public LogFilter {

public:
	FileRecorderFilter(const std::string& name,const std::string& fileName, const std::vector<std::string> filters);

	~FileRecorderFilter();

	virtual void run();

protected:

private:

	bool verifyLogMessage(const LogMessage& logMessage);

	static const std::string DELIMITER;

	std::string fileName_;

	std::vector<std::string> filters_;
};



#endif /* INCLUDE_FILERECORDERFILTER_H_ */
