#ifndef __WIFI_H__
#define __WIFI_H__
#include <freertos/FreeRTOS.h>
#include <freertos/task.h>
#include "freertos/event_groups.h"
#include "freertos/semphr.h"
#include "nvs_flash.h"
#include "esp_wifi.h"
#include "esp_wpa2.h"
#include "esp_event.h"
#include "esp_log.h"
#include "esp_system.h"
#include "esp_netif.h"
#include "esp_smartconfig.h"
#include "mem_storge.h"
#include <string.h>
#include <stdbool.h>
#include <stdint.h>

#define WIFI_NAMESPACE  "WIFIDATA"
#define WIFI_REGION "WIFIREGION"

_Bool wifi_initialize(void);

#endif