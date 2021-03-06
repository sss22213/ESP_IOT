#ifndef __MQTT_EVENT_H__
#define __MQTT_EVENT_H__
#include <freertos/FreeRTOS.h>
#include <freertos/task.h>
#include "freertos/event_groups.h"
#include "freertos/message_buffer.h"
#include "freertos/semphr.h"
#include "device_info.h"
#include "message.h"
#include "esp_system.h"
#include "esp_event.h"
#include <string.h>

struct _mqtt_event_inform_message {
    int event_id;
    int i_value;
    float f_value;
    double d_value;
    char s_value[100];
};

typedef enum {
    IDLE = BIT0,
    SYSTEM_RESET = BIT1,
    SYSTEM_REBOOT = BIT2,
} _SYSTEM_EVENT;

EventGroupHandle_t xsystemEventGroup;

QueueHandle_t mqtt_subscribe_queue;

void mqtt_event_process(int, struct _message);
void mqtt_event_init(void);

#endif