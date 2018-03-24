#include "RabbitMQSenderPipe.h"

#include "RabbitMQPipe.h"
#include "amqp.h"
#include "amqp_framing.h"
#include "RabbitMQUtils.h"

RabbitMQSenderPipe::RabbitMQSenderPipe(const std::string& name)
: RabbitMQGenericPipe("localhost",name)
, rabbitMQPipe_(NULL){
  initialization();
}

RabbitMQSenderPipe::RabbitMQSenderPipe(const std::string& host, const std::string& name)
: RabbitMQGenericPipe(host,name)
, rabbitMQPipe_(NULL){
  initialization();
}

RabbitMQSenderPipe::~RabbitMQSenderPipe() {
  delete rabbitMQPipe_;
}

void RabbitMQSenderPipe::initialization() {
  rabbitMQPipe_ = new RabbitMQPipe(host(), name());
}

void RabbitMQSenderPipe::write(const std::string& msg) {
  amqp_basic_properties_t props;
  props._flags = AMQP_BASIC_CONTENT_TYPE_FLAG | AMQP_BASIC_DELIVERY_MODE_FLAG;
  props.content_type = amqp_cstring_bytes("text/plain");
  props.delivery_mode = 2; /* persistent delivery mode */

  RabbitMQUtils::die_on_amqp_error(amqp_basic_publish(rabbitMQPipe_->conn(),
      rabbitMQPipe_->channel(),
	  rabbitMQPipe_->exchange(),
	  rabbitMQPipe_->queue(),
      0,
      0,
      &props,
      amqp_cstring_bytes(msg.c_str())),
      "publishing message");
}




