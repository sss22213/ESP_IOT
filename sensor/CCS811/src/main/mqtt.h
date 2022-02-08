#ifndef __MQTT_H__
#define __MQTT_H__
#include <stdint.h>
#include <stddef.h>
#include <string.h>
#include <freertos/FreeRTOS.h>
#include <freertos/task.h>
#include "freertos/event_groups.h"
#include "freertos/semphr.h"
#include "esp_system.h"
#include "nvs_flash.h"
#include "esp_event.h"
#include "esp_netif.h"
#include "mqtt_client.h"
#include "mqtt_event.h"
#include "message.h"
#include "esp_tls.h"
#include "esp_ota_ops.h"
#include <sys/param.h>

void mqtt_initialize(const char*);

void mqtt_wait_connect_loop(void);

void mqtt_publish(char*, int, float);

#endif