#include "message.h"

/**
 * {"NAME":<name>,"TYPE":<type>,"VALUE":<value>,"TIMESTAMP":<timestamp>,"PID":<pid>,"VID":<vid>,"UUID":<UUID>}
 */

#define MESSAGE_SEND_PACKAGE "{\"NAME\":%s,\"TYPE\":%d,\"VALUE\":%e,\"TIMESTAMP\":%d,\"PID\":0x%d,\"VID\":0x%d,\"UUID\":%s}"
#define MESSAGE_RECEIVE_PACKAGE "{\"NAME\":%s,\"TYPE\":%d,\"VALUE\":%e,\"TIMESTAMP\":%d,\"PID\":0x%d,\"VID\":0x%d,\"UUID\":%s}"

static inline void _pack(struct _message message, char *pack_buf)
{
    sprintf(pack_buf, MESSAGE_SEND_PACKAGE, message.name, message.type, message.value, message.timestamp, message.pid, message.vid, message.uuid);
}

void message_pack(char *name, int type, float value, int timestamp, \
                    int pid, int vid, char *uuid, char *pack_buf)
{
    struct _message message = {
        .name = name,
        .type = type,
        .pid = pid,
        .timestamp = timestamp,
        .uuid = uuid,
        .value = value
    };

    _pack(message, pack_buf);
}

void message_unpack(struct _message *message, char *raw_message)
{
    sscanf(raw_message, MESSAGE_RECEIVE_PACKAGE, message->name, &(message->type), \
                &(message->value), &(message->timestamp), &(message->pid), &(message->vid), message->uuid);
}