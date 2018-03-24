
#include "RabbitMQGenericPipe.h"

RabbitMQGenericPipe::RabbitMQGenericPipe(const std::string& name)
: host_("localhost"),name_(name) {
}

RabbitMQGenericPipe::RabbitMQGenericPipe(const std::string& host, const std::string& name)
: host_(host),name_(name) {
}

RabbitMQGenericPipe::~RabbitMQGenericPipe(){
}

std::string& RabbitMQGenericPipe::host() {
  return host_;
}

std::string& RabbitMQGenericPipe::name() {
  return name_;
}


