#ifndef __device_info_H__
#define __device_info_H__
#include "esp_event.h"

#define DEVICE_NAME "CC811_device"
#define PID 555
#define VID 666
#define MQTT_BROKEN_URI "mqtt://broker.hivemq.com"
#define UUID "0x0001208V-0000-1000-8000-00805F9B34FB"

enum MQTT_SUBSCRIBE_EVENT{
    // Could not remove events.
    SYSTEM_EVENT = BIT0,
    ECHO_EVENT = BIT1,
    TIMESTAMP_EVENT = BIT2,
    // User event region.
    SENSOR_EVENT = BIT3,
};


#endif