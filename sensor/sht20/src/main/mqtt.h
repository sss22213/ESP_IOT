#ifndef __MQTT_H__
#define __MQTT_H__
#include <stdint.h>
#include <stddef.h>
#include <string.h>
#include "esp_system.h"
#include "nvs_flash.h"
#include "esp_event.h"
#include "esp_netif.h"

#include "mqtt_client.h"
#include "esp_tls.h"
#include "esp_ota_ops.h"
#include <sys/param.h>

#define URI_MAXIMUM_LENGTH  100
#define USERNAME_MAXIMUM_LENGTH  100
#define PASSWORD_MAXIMUM_LENGTH  100

#endif