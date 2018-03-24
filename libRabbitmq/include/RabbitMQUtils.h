
#ifndef INCLUDE_RABBITMQUTILS_H_
#define INCLUDE_RABBITMQUTILS_H_

#include "amqp.h"
#include "amqp_framing.h"

namespace RabbitMQUtils {

void die(char const* context);

void die_on_amqp_error(int code, char const* context);

void die_on_amqp_error(amqp_rpc_reply_t x, char const* context);

}

#endif /* INCLUDE_RABBITMQUTILS_H_ */
