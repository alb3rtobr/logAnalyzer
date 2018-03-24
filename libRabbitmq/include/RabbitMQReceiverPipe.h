
#ifndef INCLUDE_RABBITMQRECEIVERPIPE_H_
#define INCLUDE_RABBITMQRECEIVERPIPE_H_

#include "RabbitMQGenericPipe.h"

class RabbitMQReceiverPipe : public RabbitMQGenericPipe {

public:

  RabbitMQReceiverPipe(const std::string& name);

  RabbitMQReceiverPipe(const std::string& host, const std::string& name);

  ~RabbitMQReceiverPipe();

  std::string read();

protected:

  void initialization();

  RabbitMQPipe* rabbitMQPipe_;

private:

};

#endif /* INCLUDE_RABBITMQRECEIVERPIPE_H_ */
