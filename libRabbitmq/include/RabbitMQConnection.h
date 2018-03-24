

#ifndef INCLUDE_RABBITMQCONNECTION_H_
#define INCLUDE_RABBITMQCONNECTION_H_

#include <string>
#include "amqp.h"
#include "amqp_tcp_socket.h"

class RabbitMQConnection {

public:

	RabbitMQConnection(const std::string& host);

  ~RabbitMQConnection();

  amqp_connection_state_t& conn();

  amqp_channel_t& channel();

  amqp_socket_t* socket();

private:

  void initConn();

  void destroyConn();

  static const int PORT;

  static amqp_channel_t CHANNEL_NUMBER;

  std::string host_;
  amqp_connection_state_t conn_;
  amqp_socket_t* socket_;

};





#endif /* INCLUDE_RABBITMQCONNECTION_H_ */
