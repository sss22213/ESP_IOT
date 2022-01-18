#include "mqtt_event.h"

static EventGroupHandle_t s_mqtt_subscribe_event_group;

static QueueHandle_t mqtt_subscribe_queue;

void mqtt_event_init(void)
{
    s_mqtt_subscribe_event_group = xEventGroupCreate();

    mqtt_subscribe_queue = xQueueCreate(100, sizeof(struct _mqtt_event_inform_message));
}

void mqtt_event_process(int event_id, struct _message message)
{
    EventBits_t s_mqtt_subscribe_uxBits = xEventGroupGetBits(s_mqtt_subscribe_event_group);

    if ((s_mqtt_subscribe_uxBits & SYSTEM_EVENT) == SYSTEM_EVENT) {

    } else if ((s_mqtt_subscribe_uxBits & ECHO_EVENT) == ECHO_EVENT) {

    } else if ((s_mqtt_subscribe_uxBits & TIMESTAMP_EVENT) == TIMESTAMP_EVENT) {
        struct _mqtt_event_inform_message mqtt_event_inform_message;

        mqtt_event_inform_message.event_id = TIMESTAMP_EVENT;
        mqtt_event_inform_message.i_value = message.timestamp;
        //strcpy(mqtt_event_inform_message.s_value, message.timestamp);

        xQueueSend(mqtt_subscribe_queue, (void*)&mqtt_event_inform_message, 100);
    }
}