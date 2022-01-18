#ifndef __device_info_H__
#define __device_info_H__
#include "esp_event.h"

#define PID 123
#define VID 253
#define MQTT_BROKEN_URI "mqtt://broker.hivemq.com"
#define UUID "ad1561-dwd151-acrev"

enum MQTT_SUBSCRIBE_EVENT{
    // Could not remove events.
    SYSTEM_EVENT = BIT0,
    ECHO_EVENT = BIT1,
    TIMESTAMP_EVENT = BIT2,
    // User event region.
    SENSOR_EVENT = BIT3,
};


#endif