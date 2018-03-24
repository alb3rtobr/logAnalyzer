
#ifndef INCLUDE_RABBITMQPIPE_H_
#define INCLUDE_RABBITMQPIPE_H_

#include <string>
#include "amqp.h"

class RabbitMQConnection;

class RabbitMQPipe {

public:

  RabbitMQPipe(const std::string& host, const std::string& name);

  ~RabbitMQPipe();

  amqp_connection_state_t& conn();

  amqp_channel_t& channel();

  amqp_bytes_t exchange();

  amqp_bytes_t& queue();

private:

  void initialization();

  static const amqp_bytes_t EXCHANGE;

  const std::string& host_;

  const std::string& name_;

  RabbitMQConnection* rabbitMQConnection_;

  amqp_bytes_t queue_;
};


#endif /* INCLUDE_RABBITMQPIPE_H_ */
