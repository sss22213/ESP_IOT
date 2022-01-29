#include "message.h"

/**
 * {"NAME":<name>,"TYPE":<type>,"VALUE":<value>,"ARG":<arg>,"TIMESTAMP":<timestamp>,"PID":<pid>,"VID":<vid>,"UUID":<UUID>}
 */

#define MESSAGE_SEND_PACKAGE "{\"NAME\":\"%s\",\"TYPE\":%d,\"VALUE\":%e,\"ARG\":%e,\"TIMESTAMP\":%d,\"PID\":%d,\"VID\":%d,\"UUID\":\"%s\"}"
#define MESSAGE_RECEIVE_PACKAGE "{\"NAME\":\"%[a-zA-Z0-9_]\",\"TYPE\":%d,\"VALUE\":%e,\"ARG\":%e,\"TIMESTAMP\":%d,\"PID\":%d,\"VID\":0x%d,\"UUID\":\"%[a-zA-Z0-9x-]\"}"

static inline void _pack(struct _message message, char *pack_buf)
{
    sprintf(pack_buf, MESSAGE_SEND_PACKAGE, message.name, message.type, message.value, message.arg0, message.timestamp, message.pid, message.vid, message.uuid);
}

void message_pack(char *name, int type, float value,  float arg, int timestamp, \
                   int pid, int vid, char *uuid, char *pack_buf)
{
    struct _message message = {
        .type = type,
        .pid = pid,
        .arg0 = arg,
        .timestamp = timestamp,
        .value = value
    };

    sprintf(message.name, "%s", name);
    sprintf(message.uuid, "%s", uuid);

    _pack(message, pack_buf);
}

void message_unpack(struct _message *message, char *raw_message)
{
    sscanf(raw_message, MESSAGE_RECEIVE_PACKAGE, message->name, &(message->type), \
                &(message->value),  &(message->arg0), &(message->timestamp), &(message->pid), \
                &(message->vid), message->uuid);
}