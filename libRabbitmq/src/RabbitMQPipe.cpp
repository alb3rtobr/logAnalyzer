#include "RabbitMQPipe.h"
#include <cstddef>
#include "RabbitMQConnection.h"
#include "RabbitMQUtils.h"
#include "amqp_framing.h"

const ::amqp_bytes_t RabbitMQPipe::EXCHANGE = ::amqp_cstring_bytes("amq.direct");

RabbitMQPipe::RabbitMQPipe(const std::string& host, const std::string& name)
: host_(host)
, name_(name)
, rabbitMQConnection_(NULL)
, queue_() {
  initialization();}

RabbitMQPipe::~RabbitMQPipe() {
  delete rabbitMQConnection_;
}

amqp_connection_state_t& RabbitMQPipe::conn() {
  return rabbitMQConnection_->conn();
}

amqp_channel_t& RabbitMQPipe::channel() {
  return rabbitMQConnection_->channel();
}

amqp_bytes_t RabbitMQPipe::exchange() {
  return RabbitMQPipe::EXCHANGE;
}

amqp_bytes_t& RabbitMQPipe::queue() {
  return queue_;
}

void RabbitMQPipe::initialization() {
  rabbitMQConnection_ = new RabbitMQConnection(host_);

  queue_ = ::amqp_cstring_bytes(name_.c_str());
  ::amqp_queue_declare(
      rabbitMQConnection_->conn(),
      rabbitMQConnection_->channel(),
      queue_,
      0,
      0,
      0,
      1,
      ::amqp_empty_table);
  RabbitMQUtils::die_on_amqp_error(::amqp_get_rpc_reply(rabbitMQConnection_->conn()),
      "declaring amqp queue");

  ::amqp_queue_bind(
      rabbitMQConnection_->conn(),
      rabbitMQConnection_->channel(),
      queue_,
	  RabbitMQPipe::EXCHANGE,
       queue_,
       ::amqp_empty_table);
  RabbitMQUtils::die_on_amqp_error(::amqp_get_rpc_reply(rabbitMQConnection_->conn()),
      "binding amqp queue");
}


