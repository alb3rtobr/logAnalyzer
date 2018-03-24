
#include "RabbitMQUtils.h"
#include <cstdarg>
#include <cstdlib>
#include <cstdio>
#include <cstring>
#include <cstdint>
#include <cctype>
#include <stdexcept>
#include <sstream>

namespace RabbitMQUtils {

void die(char const* context) {
  throw ::std::runtime_error(::std::string(context));
}

void die_on_amqp_error(int code, char const* context) {
  if (code == AMQP_STATUS_OK) {
    return;
  }
  ::std::ostringstream errMsg;
  errMsg << context << ':' << amqp_error_string2(code);
  throw ::std::runtime_error(::std::string(errMsg.str()));
}

void die_on_amqp_error(amqp_rpc_reply_t x, char const* context) {
  ::std::ostringstream errMsg;

  switch (x.reply_type) {
  case AMQP_RESPONSE_NORMAL:
    return;

  case AMQP_RESPONSE_NONE:
    errMsg << context << ": missing RPC reply type";
    break;

  case AMQP_RESPONSE_LIBRARY_EXCEPTION:
    errMsg << context << ": " <<  amqp_error_string2(x.library_error);
    break;

  case AMQP_RESPONSE_SERVER_EXCEPTION:
    switch (x.reply.id) {
    case AMQP_CONNECTION_CLOSE_METHOD: {
      amqp_connection_close_t *m = (amqp_connection_close_t *) x.reply.decoded;
      errMsg << context
          << ": server connection error " << m->reply_code
          << ", message: " << ::std::string(((char *) m->reply_text.bytes),
              (int) m->reply_text.len) << '.';
      break;
    }
    case AMQP_CHANNEL_CLOSE_METHOD: {
      amqp_channel_close_t *m = (amqp_channel_close_t *) x.reply.decoded;
      errMsg << context
          << ": server channel error " << m->reply_code
          << ", message: " << ::std::string(((char *) m->reply_text.bytes),
              (int) m->reply_text.len) << '.';
      break;
    }
    default:
      errMsg << context << ":unknown server error, method id " << x.reply.id;
      break;
    }
    break;
  }

  throw ::std::runtime_error(errMsg.str());
}

}

