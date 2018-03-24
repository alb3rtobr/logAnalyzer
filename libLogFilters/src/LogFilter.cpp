
#include "LogFilter.h"

LogFilter::LogFilter(const std::string& name, const std::string& destination)
: name_(name)
, destination_(destination)
, receiverPipe_(name)
, senderPipe_(destination)
, logSerializer_(){

}

LogFilter::~LogFilter(){

}


