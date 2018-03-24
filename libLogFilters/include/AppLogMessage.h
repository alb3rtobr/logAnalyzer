
#ifndef INCLUDE_APPLOGMESSAGE_H_
#define INCLUDE_APPLOGMESSAGE_H_

class AppLogMessage : public LogMessage {

public:

	AppLogMessage(const std::string& message);

	AppLogMessage(const std::string& serializedLog);

	~AppLogMessage();

	std::string toString();

protected:

private:

};

#endif /* INCLUDE_APPLOGMESSAGE_H_ */
