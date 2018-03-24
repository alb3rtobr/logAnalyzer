
#include "RabbitMQSenderPipe.h"
#include "RabbitMQReceiverPipe.h"
#include "LogIdentifier.h"
#include "LogSerializer.h"

const std::string LogIdentifier::SYSTEM_LOG_DESTINATION = "SystemLogNormalizerBroker";
const std::string  LogIdentifier::APP_LOG_DESTINATION = "AppLogNormalizerBroker";

LogIdentifier::LogIdentifier(const std::string& name, const std::string& appDestination,const std::string& systemDestination)
: LogFilter(name,"")
, systemLogSender_(systemDestination)
, appLogSender_(appDestination){
}

LogIdentifier::~LogIdentifier(){
}


void LogIdentifier::run(){
	std::cout << "#### PROCESS " << name_ << " sending to " << SYSTEM_LOG_DESTINATION << " and " << APP_LOG_DESTINATION << " ####\n" << std::endl;
	while(1){
			std::string msg(receiverPipe_.read());

			std::cout << "IN" << std::endl;
			std::cout << "\t" << msg << std::endl;

			LogMessage logMessage = buildLogMessageObjectFromRawLog(msg);

			if ( verifyLogMessage(logMessage) ){
				std::string outputMessage = logSerializer_.buildSerializedLogMessage(logMessage);
				std::string destination;
				if ( isAppLog(logMessage.getRawLogText()) ){
					appLogSender_.write( outputMessage );
					destination=APP_LOG_DESTINATION;
				}else{
					systemLogSender_.write( outputMessage );
					destination=SYSTEM_LOG_DESTINATION;
				}
				std::cout << "OUT (" << destination << ")" << std::endl;
				std::cout << "\t" << outputMessage << std::endl;
			}

			std::cout << "\n----------------------\n" << std::endl;
		}
}

LogMessage LogIdentifier::buildLogMessageObjectFromRawLog(const std::string& message){
	std::string timestamp, rawLogText;
	std::size_t firstSpace=message.find(" ");
	timestamp=message.substr(0,firstSpace);
	if ( firstSpace != std::string::npos ){
		rawLogText=message.substr(message.find(" ")+1);
	}
	LogMessage logMessage(timestamp,rawLogText);
	return logMessage;
}

bool LogIdentifier::verifyLogMessage(const LogMessage& logMessage){
	bool result=true;
	if (logMessage.getTimestamp().empty() || logMessage.getRawLogText().empty()){
		result=false;
	}
	return result;
}

bool LogIdentifier::isAppLog(const std::string& rawLog){
	bool result(false);
	bool debugTagFound(rawLog.find("DEBUG") == 0 );
	bool warnTagFound(rawLog.find("WARN") == 0);
	bool errorTagFound(rawLog.find("ERROR") == 0);

	if(debugTagFound || warnTagFound || errorTagFound){
		result=true;
	}
	return result;
}

void LogIdentifier::processMessage(const std::string& message){
	//
}
