
#include "RabbitMQConnection.h"
#include "RabbitMQUtils.h"
#include <cstddef>
#include "amqp_framing.h"


const int RabbitMQConnection::PORT = 5672;
amqp_channel_t RabbitMQConnection::CHANNEL_NUMBER = 1;

RabbitMQConnection::RabbitMQConnection(const std::string& host)
: host_(host)
, conn_()
, socket_(NULL) {
  initConn();
}

RabbitMQConnection::~RabbitMQConnection() {
  destroyConn();
}

amqp_connection_state_t& RabbitMQConnection::conn() {
  return conn_;
}

amqp_channel_t& RabbitMQConnection::channel() {
  return RabbitMQConnection::CHANNEL_NUMBER;
}

amqp_socket_t* RabbitMQConnection::socket() {
  return socket_;
}

void RabbitMQConnection::initConn() {
  conn_ = amqp_new_connection();
  if (conn_ == NULL) {
	  RabbitMQUtils::die("creating amqp connection");
  }

  socket_ = amqp_tcp_socket_new(conn_);
  if (socket_ == NULL) {
	  RabbitMQUtils::die("creating amqp TCP socket");
  }

  int status = amqp_socket_open(socket_, host_.c_str(),
		  RabbitMQConnection::PORT);
  if (status != ::AMQP_STATUS_OK) {
	  RabbitMQUtils::die("opening amqp TCP socket");
  }

  RabbitMQUtils::die_on_amqp_error(
      amqp_login(conn_,
          "/",
          AMQP_DEFAULT_MAX_CHANNELS,
          AMQP_DEFAULT_FRAME_SIZE,
          0,
          ::AMQP_SASL_METHOD_PLAIN,
           "guest",
           "guest"),
           "logging into amqp");

  amqp_channel_open(conn_, RabbitMQConnection::CHANNEL_NUMBER);
  RabbitMQUtils::die_on_amqp_error(::amqp_get_rpc_reply(conn_),
      "opening amqp channel");
}

void RabbitMQConnection::destroyConn() {
	RabbitMQUtils::die_on_amqp_error(::amqp_channel_close(
      conn_,
	  RabbitMQConnection::CHANNEL_NUMBER,
      AMQP_REPLY_SUCCESS),
      "closing amqp channel");

	RabbitMQUtils::die_on_amqp_error(::amqp_connection_close(
      conn_,
      AMQP_REPLY_SUCCESS),
      "closing amqp connection");

	RabbitMQUtils::die_on_amqp_error(::amqp_destroy_connection(
      conn_),
      "ending amqp connection");
}




