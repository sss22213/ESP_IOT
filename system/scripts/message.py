'''
{"NAME":<name>,"TYPE":<type>,"VALUE":<value>,"ARG":<arg>,"TIMESTAMP":<timestamp>,
"PID":<pid>,"VID":<vid>,"UUID":<UUID>}

struct _message {
    char *name;
    int type;
    float value;
    float arg0;
    int timestamp;
    int pid;
    int vid; 
    char *uuid;
};
    SYSTEM_EVENT = BIT0,
    ECHO_EVENT = BIT1,
    TIMESTAMP_EVENT = BIT2,
'''

_MESSAGE_TYPE_SYSTEM_EVENT = (1 << 0)
_MESSAGE_TYPE_ECHO_EVENT = (1 << 1)
_MESSAGE_TYPE_TIMESTAMP_EVENT = (1 << 2)

class _message:
    topic_name = "SYSTEM"
    message_type = 0
    value = 0
    arg = 0
    timestamp = 0
    pid = 0x000
    vid = 0x000
    uuid = "0x00000000-0000-1000-8000-00805F9B34FB"

    def generate():
        pass