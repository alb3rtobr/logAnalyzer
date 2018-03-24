

#include "AppLogNormalizer.h"

AppLogNormalizer::AppLogNormalizer(const std::string& name, const std::string& destination)
: LogFilter(name,destination){
}

AppLogNormalizer::~AppLogNormalizer(){}

void AppLogNormalizer::run(){
	std::cout << "#### PROCESS " << name_ << " sending to " << destination_ << " ####\n" << std::endl;
		while(1){
				std::string msg(receiverPipe_.read());

				std::cout << "IN" << std::endl;
				std::cout << "\t" << msg << std::endl;

				LogMessage logMessage = logSerializer_.buildLogMessageObject(msg);

				if ( verifyLogMessage(logMessage) ){

					logMessage.component_=extractComponent(logMessage.getRawLogText());
					logMessage.severity_=extractSeverity(logMessage.getRawLogText());
					logMessage.logText_=extractLogText(logMessage.getRawLogText());

					std::string outputMessage = logSerializer_.buildSerializedLogMessage(logMessage);

					std::cout << "OUT (" << destination_ << ")" << std::endl;
					std::cout << "\t" << outputMessage << std::endl;
					senderPipe_.write( outputMessage );
				}

				std::cout << "\n----------------------\n" << std::endl;

		}
}

bool AppLogNormalizer::verifyLogMessage(const LogMessage& logMessage){
	bool result=true;
	if (logMessage.getTimestamp().empty() || logMessage.getRawLogText().empty()){
		result=false;
	}
	return result;
}

std::string AppLogNormalizer::extractComponent(const std::string& rawLog){
	std::string aux=rawLog.substr(rawLog.find(" ")+1);
	return aux.substr(0,aux.find(" "));
}

std::string AppLogNormalizer::extractSeverity(const std::string& rawLog){
	return rawLog.substr(0,rawLog.find(" "));
}

std::string AppLogNormalizer::extractLogText(const std::string& rawLog){
	std::string aux=rawLog.substr(rawLog.find(" ")+1); //discard severity
	std::string aux2=aux.substr(aux.find(" ")+1); // discard component
	return aux2.substr(aux2.find(" ")+1); //discard classname
}

