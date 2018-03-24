
#include "WordSeparator.h"

WordSeparator::WordSeparator(const std::string& name, const std::string& destination)
: LogFilter(name, destination){
}

WordSeparator::~WordSeparator(){}

void WordSeparator::run(){
	std::cout << "#### PROCESS " << name_ << " sending to " << destination_ << " ####\n" << std::endl;
			while(1){
					std::string msg(receiverPipe_.read());

					std::cout << "IN" << std::endl;
					std::cout << "\t" << msg << std::endl;

					LogMessage logMessage = logSerializer_.buildLogMessageObject(msg);

					if ( verifyLogMessage(logMessage) ){

						//logText pasarlo a un vector de strings
						std::istringstream iss(logMessage.logText_);
						std::string token;
						while (std::getline(iss, token, ' '))
						{
						    logMessage.words_.push_back(token);
						}

						std::string outputMessage = logSerializer_.buildSerializedLogMessage(logMessage);

						std::cout << "OUT (" << destination_ << ")" << std::endl;
						std::cout << "\t" << outputMessage << std::endl;
						senderPipe_.write( outputMessage );
					}

					std::cout << "\n----------------------\n" << std::endl;

			}
}

bool WordSeparator::verifyLogMessage(const LogMessage& logMessage){
	bool result=true;
	if (logMessage.getTimestamp().empty() ||
		logMessage.getRawLogText().empty() ||
		logMessage.severity_.empty() ||
		logMessage.component_.empty() ||
		logMessage.logText_.empty()
		){
			result=false;
		}
	return true;
}

