
#ifndef INCLUDE_LOGSERIALIZER_H_
#define INCLUDE_LOGSERIALIZER_H_

#include "LogMessage.h"

class LogSerializer{

public:

	LogSerializer();

	LogMessage buildLogMessageObject(const std::string& serializedLogMessage);

	std::string buildSerializedLogMessage(const LogMessage& logMessage);

protected:

private:

	std::vector<std::string> buildWordsVector(const std::string& wordsString);

	std::string extractAttribute(const std::string& serializedLogMessage, const std::string& beginTag, const std::string& endTag);

	static const std::string LOGMESSAGE_BEGIN_TAG;

	static const std::string LOGMESSAGE_END_TAG;

	static const std::string TIMESTAMP_BEGIN_TAG;

	static const std::string TIMESTAMP_END_TAG;

	static const std::string RAWLOGTEXT_BEGIN_TAG;

	static const std::string RAWLOGTEXT_END_TAG;

	static const std::string COMPONENT_BEGIN_TAG;

	static const std::string COMPONENT_END_TAG;

	static const std::string SEVERITY_BEGIN_TAG;

	static const std::string SEVERITY_END_TAG;

	static const std::string LOGTEXT_BEGIN_TAG;

	static const std::string LOGTEXT_END_TAG;

	static const std::string WORDS_BEGIN_TAG;

	static const std::string WORDS_END_TAG;

	static const std::string WORD_BEGIN_TAG;

	static const std::string WORD_END_TAG;

};



#endif /* INCLUDE_LOGSERIALIZER_H_ */
