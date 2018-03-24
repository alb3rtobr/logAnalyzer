
#ifndef INCLUDE_RABBITMQGENERICPIPE_H_
#define INCLUDE_RABBITMQGENERICPIPE_H_

#include "RabbitMQPipe.h"

class RabbitMQGenericPipe {

public:

  RabbitMQGenericPipe(const std::string& name);

  RabbitMQGenericPipe(const std::string& host, const std::string& name);

  virtual ~RabbitMQGenericPipe();

protected:

  std::string& host();

  std::string& name();

  std::string host_;

  std::string name_;



private:

};

#endif /* INCLUDE_RABBITMQGENERICPIPE_H_ */
