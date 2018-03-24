
#include "SystemLogNormalizer.h"

const std::vector<std::string> SystemLogNormalizer::SEVERITY_LEVELS = { "ERROR", "WARN", "INFO", "DEBUG" };

SystemLogNormalizer::SystemLogNormalizer(const std::string& name, const std::string& destination)
: LogFilter(name,destination){
}

SystemLogNormalizer::~SystemLogNormalizer(){}

void SystemLogNormalizer::run(){
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

bool SystemLogNormalizer::verifyLogMessage(const LogMessage& logMessage){
	bool result=true;
	if (logMessage.getTimestamp().empty() || logMessage.getRawLogText().empty()){
		result=false;
	}
	return result;
}

std::string SystemLogNormalizer::extractComponent(const std::string& rawLog){

	return rawLog.substr(0,rawLog.find(" "));
}

std::string SystemLogNormalizer::extractSeverity(const std::string& rawLog){
	std::string aux=rawLog.substr(rawLog.find(" ")+1);
	int index = std::stoi( aux.substr(0,aux.find(" ")) );
	return SEVERITY_LEVELS[index-1];
}

std::string SystemLogNormalizer::extractLogText(const std::string& rawLog){
	std::string aux=rawLog.substr(rawLog.find(" ")+1); //discard component
	return aux.substr(aux.find(" ")+1); // discard severity
}






