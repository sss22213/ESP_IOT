#ifndef __SYSTEM_TASK_H__
#define __SYSTEM_TASK_H__
#include <freertos/FreeRTOS.h>
#include <freertos/task.h>
#include "freertos/event_groups.h"
#include "freertos/semphr.h"
#include "device_info.h"
#include "message.h"
#include "mqtt_event.h"
#include "esp_system.h"
#include "esp_event.h"
#include <string.h>

void system_task_process(void*);

#endif