

#ifndef INCLUDE_LOGMESSAGE_H_
#define INCLUDE_LOGMESSAGE_H_

#include <vector>
#include <string>

class LogMessage{
public:
	LogMessage(const std::string& timestamp, const std::string& rawLogText);

	virtual ~LogMessage();

	void setComponent(const std::string& component);

	void setSeverity(const std::string& severity);

	void setLogText(const std::string& logText);

	std::string getTimestamp() const;

	std::string getRawLogText() const;

	std::string component_;

	std::string severity_;

	std::string logText_;

	std::vector<std::string> words_;

protected:


private:

	std::string rawLogText_; //The message after the timestamp

	std::string timestamp_;

};



#endif /* INCLUDE_LOGMESSAGE_H_ */
