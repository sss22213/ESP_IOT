#ifndef __MQTT_EVENT_H__
#define __MQTT_EVENT_H__
#include <freertos/FreeRTOS.h>
#include <freertos/task.h>
#include "freertos/event_groups.h"
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

void mqtt_event_process(int, struct _message);

#endif