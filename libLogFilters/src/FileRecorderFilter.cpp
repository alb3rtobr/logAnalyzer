
#include "FileRecorderFilter.h"

const std::string FileRecorderFilter::DELIMITER="--";

FileRecorderFilter::FileRecorderFilter(const std::string& name,const std::string& fileName, const std::vector<std::string> filters)
: LogFilter(name,"")
, fileName_(fileName){
	filters_=filters;
}

FileRecorderFilter::~FileRecorderFilter(){}


void FileRecorderFilter::run(){
	std::cout << "#### PROCESS " << name_ << " writing to " << fileName_ << " ####\n" << std::endl;
		while(1){
			std::string msg(receiverPipe_.read());

			std::cout << "IN" << std::endl;
			std::cout << "\t" << msg << std::endl;

			LogMessage logMessage = logSerializer_.buildLogMessageObject(msg);

			if ( verifyLogMessage(logMessage) ){

				bool found=false;
				for( std::string word : logMessage.words_){
					for (std::string filter : filters_){
						if ( word.compare(filter) == 0 ){
							found=true;
							break;
						}
					}
					if (found) break;
				}


				std::string outputMessage = logSerializer_.buildSerializedLogMessage(logMessage);
				if (found){
					std::cout << "WRITTING LOG to " << fileName_ << std::endl;
					std::ofstream out(fileName_,std::ofstream::app);
					out << "\n" << logMessage.getTimestamp();
					out << "\n" << logMessage.component_;
					out << "\n" << logMessage.severity_;
					out << "\n";
					std::string allWords;
					for (std::string word : logMessage.words_){
						allWords += word;
						allWords += " ";
					}
					allWords=allWords.substr(0,allWords.size()-1);
					out << allWords << "\n" << DELIMITER;
					out.close();
				}else{
					std::cout << "DISCARDING LOG " << std::endl;
				}
				std::cout << "\t" << outputMessage << std::endl;

			}

			std::cout << "\n----------------------\n" << std::endl;

		}
}

bool FileRecorderFilter::verifyLogMessage(const LogMessage& logMessage){
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


