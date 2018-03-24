#include "StandardRecorder.h"

const std::string StandardRecorder::OUTPUT_FILENAME="standard.log";

const std::string StandardRecorder::DELIMITER="--";

StandardRecorder::StandardRecorder(const std::string& name, const std::vector<std::string> destinationPipes)
: LogFilter(name,"")
{
	destinationPipeNames_=destinationPipes;
	for (std::string pipeName : destinationPipeNames_ ){

		outputPipes_.push_back(new RabbitMQSenderPipe(pipeName));

	}

}

StandardRecorder::~StandardRecorder(){}

void StandardRecorder::run(){
	std::cout << "#### PROCESS " << name_ << " sending to " << getPipeNamesAsString() << " ####\n" << std::endl;
	while(1){
		std::string msg(receiverPipe_.read());

		std::cout << "IN" << std::endl;
		std::cout << "\t" << msg << std::endl;

		LogMessage logMessage = logSerializer_.buildLogMessageObject(msg);

		if ( verifyLogMessage(logMessage) ){
			std::ofstream out(OUTPUT_FILENAME,std::ofstream::app);
			out << "\n";
			out << logMessage.getTimestamp();
			out << "\n";
			out << logMessage.component_;
			out << "\n";
			out << logMessage.severity_;
			out << "\n";
			std::string allWords;
			for (std::string word : logMessage.words_){
				allWords += word;
				allWords += " ";
			}
			allWords=allWords.substr(0,allWords.size()-1);
			out << allWords;
			out << "\n";
			out << DELIMITER;
			out.close();

			std::string outputMessage = logSerializer_.buildSerializedLogMessage(logMessage);

			std::cout << "OUT (" << getPipeNamesAsString() << ")" << std::endl;
			std::cout << "\t" << outputMessage << std::endl;

			for (auto iterator=outputPipes_.begin(); iterator != outputPipes_.end(); iterator++){
				(*iterator)->write(outputMessage);
			}
		}

		std::cout << "\n----------------------\n" << std::endl;

	}
}

bool StandardRecorder::verifyLogMessage(const LogMessage& logMessage){
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

std::string StandardRecorder::getPipeNamesAsString(){
	std::string result="";
	for (auto iterator=destinationPipeNames_.begin();iterator!=destinationPipeNames_.end();iterator++){
		result += (*iterator);
		result += " ";
	}
	return result;
}

