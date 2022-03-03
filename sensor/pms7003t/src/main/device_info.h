#ifndef __device_info_H__
#define __device_info_H__
#include "esp_event.h"

#define DEVICE_NAME "PMS7003T"
#define PID 128
#define VID 222
#define MQTT_BROKEN_URI "mqtt://broker.hivemq.com"
#define UUID "0x007003TC-0000-1000-8000-00805F9B34FB"

enum MQTT_SUBSCRIBE_EVENT{
    // Could not remove events.
    SYSTEM_EVENT = BIT0,
    ECHO_EVENT = BIT1,
    TIMESTAMP_EVENT = BIT2,
    // User event region.
    SENSOR_EVENT = BIT3,
    CALLEE_EVENT = BIT4
};


#endif