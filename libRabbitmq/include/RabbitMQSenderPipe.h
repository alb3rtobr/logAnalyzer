
#ifndef INCLUDE_RABBITMQSENDERPIPE_H_
#define INCLUDE_RABBITMQSENDERPIPE_H_


#include "RabbitMQGenericPipe.h"

class RabbitMQSenderPipe : public RabbitMQGenericPipe {

public:

  RabbitMQSenderPipe(const std::string& name);

  RabbitMQSenderPipe(const std::string& host, const std::string& name);

  ~RabbitMQSenderPipe();

  void write(const std::string& msg);

protected:

  void initialization();

  RabbitMQPipe* rabbitMQPipe_;

private:

};


#endif /* INCLUDE_RABBITMQSENDERPIPE_H_ */
