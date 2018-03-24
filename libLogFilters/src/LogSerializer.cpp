#include <string>
#include <iostream>
#include "LogSerializer.h"

const std::string LogSerializer::LOGMESSAGE_BEGIN_TAG = "<LogMessage>";
const std::string LogSerializer::LOGMESSAGE_END_TAG = "</LogMessage>";
const std::string LogSerializer::TIMESTAMP_BEGIN_TAG = "<Timestamp>";
const std::string LogSerializer::TIMESTAMP_END_TAG = "</Timestamp>";
const std::string LogSerializer::RAWLOGTEXT_BEGIN_TAG = "<RawLogText>";
const std::string LogSerializer::RAWLOGTEXT_END_TAG = "</RawLogText>";
const std::string LogSerializer::COMPONENT_BEGIN_TAG = "<Component>";
const std::string LogSerializer::COMPONENT_END_TAG = "</Component>";
const std::string LogSerializer::SEVERITY_BEGIN_TAG = "<Severity>";
const std::string LogSerializer::SEVERITY_END_TAG = "</Severity>";
const std::string LogSerializer::LOGTEXT_BEGIN_TAG = "<LogText>";
const std::string LogSerializer::LOGTEXT_END_TAG = "</LogText>";
const std::string LogSerializer::WORDS_BEGIN_TAG = "<Words>";
const std::string LogSerializer::WORDS_END_TAG = "</Words>";
const std::string LogSerializer::WORD_BEGIN_TAG = "<Word>";
const std::string LogSerializer::WORD_END_TAG = "</Word>";


LogSerializer::LogSerializer(){

}

LogMessage LogSerializer::buildLogMessageObject(const std::string& serializedLogMessage){

	std::string timestamp,rawLogText,component,severity,logText,words;

	timestamp = extractAttribute(serializedLogMessage,LogSerializer::TIMESTAMP_BEGIN_TAG,LogSerializer::TIMESTAMP_END_TAG);
	rawLogText = extractAttribute(serializedLogMessage,LogSerializer::RAWLOGTEXT_BEGIN_TAG,LogSerializer::RAWLOGTEXT_END_TAG);

	LogMessage logMessage(timestamp,rawLogText);

	component = extractAttribute(serializedLogMessage,LogSerializer::COMPONENT_BEGIN_TAG,LogSerializer::COMPONENT_END_TAG);
	severity = extractAttribute(serializedLogMessage,LogSerializer::SEVERITY_BEGIN_TAG,LogSerializer::SEVERITY_END_TAG);
	logText = extractAttribute(serializedLogMessage,LogSerializer::LOGTEXT_BEGIN_TAG,LogSerializer::LOGTEXT_END_TAG);
	words = extractAttribute(serializedLogMessage,LogSerializer::WORDS_BEGIN_TAG,LogSerializer::WORDS_END_TAG);

	if (!component.empty()){
		logMessage.component_=component;
	}
	if (!severity.empty()){
		logMessage.severity_=severity;
	}
	if (!logText.empty()){
		logMessage.logText_=logText;
	}
	if (!words.empty()){
		logMessage.words_=buildWordsVector(words);
	}

	return logMessage;
}

std::vector<std::string> LogSerializer::buildWordsVector(const std::string& wordsString){
	//wordString="<Word>hola</Word><Word>adios</Word>"
	std::vector<std::string> wordsVector;
	std::string words=wordsString;
	std::string delimiter=WORD_END_TAG;
	bool fin=false;
	while(!fin){
		size_t index = words.find(delimiter);
		if (index == std::string::npos){
			fin=true;
		}else{
			std::string token=words.substr(0,index); //<Word>hola
			token=token.substr(WORD_BEGIN_TAG.size());
			wordsVector.push_back(token);
			words=words.substr(index+delimiter.size());
		}
	}
	return wordsVector;
}

std::string LogSerializer::extractAttribute(const std::string& serializedLogMessage, const std::string& beginTag, const std::string& endTag){
	std::size_t beginTagPos, endTagPos;

	std::string result;

	beginTagPos = serializedLogMessage.find(beginTag);
	endTagPos = serializedLogMessage.find(endTag);

	if (beginTagPos != std::string::npos && endTagPos != std::string::npos){

		int beginIndex = beginTagPos + beginTag.size();
		int attrLength = endTagPos-beginIndex;

		result = serializedLogMessage.substr(beginIndex,attrLength);
	}

	return result;
}


std::string LogSerializer::buildSerializedLogMessage(const LogMessage& logMessage){

	std::string serializedLog = LogSerializer::LOGMESSAGE_BEGIN_TAG;

	serializedLog += LogSerializer::TIMESTAMP_BEGIN_TAG;
	serializedLog += logMessage.getTimestamp();
	serializedLog += LogSerializer::TIMESTAMP_END_TAG;

	serializedLog += LogSerializer::RAWLOGTEXT_BEGIN_TAG;
	serializedLog += logMessage.getRawLogText();
	serializedLog += LogSerializer::RAWLOGTEXT_END_TAG;

	if (!logMessage.component_.empty()){
		serializedLog += LogSerializer::COMPONENT_BEGIN_TAG;
		serializedLog += logMessage.component_;
		serializedLog += LogSerializer::COMPONENT_END_TAG;
	}
	if (!logMessage.severity_.empty()){
		serializedLog += LogSerializer::SEVERITY_BEGIN_TAG;
		serializedLog += logMessage.severity_;
		serializedLog += LogSerializer::SEVERITY_END_TAG;
	}
	if (!logMessage.logText_.empty()){
		serializedLog += LogSerializer::LOGTEXT_BEGIN_TAG;
		serializedLog += logMessage.logText_;
		serializedLog += LogSerializer::LOGTEXT_END_TAG;
	}
	if (!logMessage.words_.empty()){
		serializedLog += LogSerializer::WORDS_BEGIN_TAG;
		for (std::string word : logMessage.words_){
			serializedLog += LogSerializer::WORD_BEGIN_TAG;
			serializedLog += word;
			serializedLog += LogSerializer::WORD_END_TAG;
		}
		serializedLog += LogSerializer::WORDS_END_TAG;
	}

	serializedLog += LogSerializer::LOGMESSAGE_END_TAG;

	return serializedLog;

}




