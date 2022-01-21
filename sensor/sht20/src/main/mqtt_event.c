#include "mqtt_event.h"

static QueueHandle_t mqtt_subscribe_queue;

extern void mqtt_publish(char*, int, float);

void mqtt_event_init(void)
{
    mqtt_subscribe_queue = xQueueCreate(1024, sizeof(struct _mqtt_event_inform_message*));
}

void mqtt_event_process(int event_id, struct _message message)
{
    if ((event_id & SYSTEM_EVENT) == SYSTEM_EVENT) {
        struct _mqtt_event_inform_message *ptr_mqtt_event_inform_message;
        mqtt_event_inform_message.event_id = SYSTEM_EVENT;
        mqtt_event_inform_message.f_value = message.value;

        printf("SYSTEM_EVENT is triggered.\n");

        xQueueSend(mqtt_subscribe_queue, &ptr_mqtt_event_inform_message, 100);

    } else if ((event_id & ECHO_EVENT) == ECHO_EVENT) {
        mqtt_publish(DEVICE_NAME, ECHO_EVENT, -1.0);

        printf("ECHO_EVENT is triggered.\n");

    } else if ((event_id & TIMESTAMP_EVENT) == TIMESTAMP_EVENT) {
        struct _mqtt_event_inform_message *ptr_mqtt_event_inform_message;
        mqtt_event_inform_message.event_id = TIMESTAMP_EVENT;
        mqtt_event_inform_message.i_value = message.timestamp;

        printf("TIMESTAMP_EVENT is triggered.\n");

        ptr_mqtt_event_inform_message = &mqtt_event_inform_message;

        xQueueSend(mqtt_subscribe_queue, &ptr_mqtt_event_inform_message, 10);

    } else if ((event_id & SENSOR_EVENT) == SENSOR_EVENT) {
        printf("SENSOR_EVENT is triggered.\n");
    } else {
        printf("%d\n", event_id);
    }
}