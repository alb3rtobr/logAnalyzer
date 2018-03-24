
#include "LogMessage.h"

LogMessage::LogMessage(const std::string& timestamp, const std::string& rawLogText){
	timestamp_ = timestamp;
	rawLogText_ = rawLogText;
}

LogMessage::~LogMessage(){
}

std::string LogMessage::getTimestamp() const{
	return timestamp_;
}

std::string LogMessage::getRawLogText() const{
	return rawLogText_;
}
