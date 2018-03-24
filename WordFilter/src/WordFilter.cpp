#include "WordFilter.h"

WordFilter::WordFilter(const std::string& name, const std::string& destination)
:LogFilter(name,destination){

}

WordFilter::~WordFilter(){}

void WordFilter::run(){
	std::cout << "#### PROCESS " << name_ << " sending to " << destination_ << " ####\n" << std::endl;
	while(1){
		std::string msg(receiverPipe_.read());

		std::cout << "IN" << std::endl;
		std::cout << "\t" << msg << std::endl;

		LogMessage logMessage = logSerializer_.buildLogMessageObject(msg);

		if ( verifyLogMessage(logMessage) ){

			std::vector<std::string> newWords;
			for( std::string word : logMessage.words_){
				if (word.size() > 3){
					newWords.push_back(word);
				}
			}

			logMessage.words_=newWords;
			std::string outputMessage = logSerializer_.buildSerializedLogMessage(logMessage);

			std::cout << "OUT (" << destination_ << ")" << std::endl;
			std::cout << "\t" << outputMessage << std::endl;
			senderPipe_.write( outputMessage );
		}

		std::cout << "\n----------------------\n" << std::endl;

	}
}


bool WordFilter::verifyLogMessage(const LogMessage& logMessage){
	//A message is valid if all the fields are not empty
	bool result=true;
	if (logMessage.getTimestamp().empty() ||
			logMessage.getRawLogText().empty() ||
			logMessage.severity_.empty() ||
			logMessage.component_.empty() ||
			logMessage.logText_.empty() ||
			logMessage.words_.empty()
	){
		result=false;
	}
	return result;
}



