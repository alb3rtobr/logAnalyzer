

#ifndef INCLUDE_SYSTEMLOGMESSAGE_H_
#define INCLUDE_SYSTEMLOGMESSAGE_H_

class SystemLogMessage : public LogMessage {

public:

	SystemLogMessage(const std::string& message);

	SystemLogMessage(const std::string& serializedLog);

	~SystemLogMessage();

	std::string toString();

protected:

private:

};

#endif /* INCLUDE_SYSTEMLOGMESSAGE_H_ */
