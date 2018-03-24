
#include "RabbitMQReceiverPipe.h"

#include "RabbitMQPipe.h"
#include "amqp.h"
#include "amqp_framing.h"
#include "RabbitMQUtils.h"

RabbitMQReceiverPipe::RabbitMQReceiverPipe(const std::string& name)
: RabbitMQGenericPipe("localhost", name)
, rabbitMQPipe_(NULL) {
  initialization();
}

RabbitMQReceiverPipe::RabbitMQReceiverPipe(const std::string& host, const std::string& name)
: RabbitMQGenericPipe(host, name)
, rabbitMQPipe_(NULL) {
  initialization();
}

RabbitMQReceiverPipe::~RabbitMQReceiverPipe() {
  delete rabbitMQPipe_;
}

void RabbitMQReceiverPipe::initialization() {
  rabbitMQPipe_ = new RabbitMQPipe(host(), name());

  amqp_basic_consume(
      rabbitMQPipe_->conn(),
      rabbitMQPipe_->channel(),
      rabbitMQPipe_->queue(),
      amqp_empty_bytes,
      0,
      1,
      0,
      ::amqp_empty_table);
  RabbitMQUtils::die_on_amqp_error(amqp_get_rpc_reply(rabbitMQPipe_->conn()),"amqp consuming");
}

std::string RabbitMQReceiverPipe::read() {
  amqp_envelope_t envelope;

  amqp_maybe_release_buffers(rabbitMQPipe_->conn());

  RabbitMQUtils::die_on_amqp_error(amqp_consume_message(rabbitMQPipe_->conn(),
      &envelope, NULL, 0), "consuming message");

  std::string msg(static_cast<const char*>(envelope.message.body.bytes),
      envelope.message.body.len);

  amqp_destroy_envelope(&envelope);

  return msg;
}



