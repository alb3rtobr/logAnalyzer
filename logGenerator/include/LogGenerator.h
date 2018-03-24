
#ifndef LOGGENERATOR_H_
#define LOGGENERATOR_H_

#include <string>
#include <vector>
#include <sstream>

class LogGenerator{

public:

	std::string generateRandomLog();

protected:

private:

	std::string generateAppLog();

	std::string generateSystemLog();

	std::string generateTimestamp();

	std::string generateSystemSeverity();

	std::string generateAppSeverity();

	std::string generateComponentName();

	std::string generateClassName();

	std::string generateLogText();

	static const std::vector<std::string> components_;

	static const std::vector<std::string> classNames_;

	static const std::vector<std::string> logTexts_;

	static const std::vector<std::string> appSeverityLevels_;
};




#endif /* LOGGENERATOR_H_ */
