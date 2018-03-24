
#include "LogGenerator.h"

const std::vector<std::string> LogGenerator::components_={
		"bitcoin_generator",
		"security_module",
		"network_manager",
		"stormtrooper_killer",
		"darthvader_detector"
};

const std::vector<std::string> LogGenerator::classNames_={
		"Utils",
		"main",
		"Logger",
		"Runner"
};

const std::vector<std::string> LogGenerator::logTexts_={
		"Luke I am your father",
		"something went wrong with this component",
		"incorrect password",
		"process aborted.",
		"kernel panic",
		"nice coredump generated",
		"timeout while destroying galactic empire",
		"nuclear meltdown please save all your work in progress",
		"the princess is in another castle",
		"database timeout please help me.",
		"unexpected behavior fine."
};

const std::vector<std::string> LogGenerator::appSeverityLevels_ = { "ERROR", "WARN", "INFO", "DEBUG" };

std::string LogGenerator::generateRandomLog(){
	std::string result;
	if ( (rand() % 2) == 0 ){
		result=generateAppLog();
	}else{
		result=generateSystemLog();
	}
	return result;
}


std::string LogGenerator::generateAppLog(){

	std::string log = generateTimestamp() + " ";
	log += generateAppSeverity() + " ";
	log += generateComponentName() + " ";
	log += generateClassName() + " ";
	log += generateLogText();

	return log;
}

std::string LogGenerator::generateSystemLog(){

	std::string log = generateTimestamp() + " ";
	log += generateComponentName() + " ";
	log += generateSystemSeverity() + " ";
	log += generateLogText();
	return log;
}

std::string LogGenerator::generateTimestamp(){
	//TODO: create random timestamps
	return "2015-09-22T09:15:46Z";
}

std::string LogGenerator::generateSystemSeverity(){
	int severity=((rand() % 4 ) + 1);
	std::stringstream ss;
	ss << severity;
	return ss.str();
}

std::string LogGenerator::generateAppSeverity(){
	int index=(rand() % appSeverityLevels_.size() ) ;
	return appSeverityLevels_[index];
}

std::string LogGenerator::generateComponentName(){
	int index=(rand() % components_.size());
	return components_[index];
}

std::string LogGenerator::generateClassName(){
	int index=(rand() % classNames_.size());
	return classNames_[index];
}

std::string LogGenerator::generateLogText(){
	int index=(rand() % logTexts_.size());
	return logTexts_[index];
}

