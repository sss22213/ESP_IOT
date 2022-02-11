#ifndef __MEM_STORGE_H__
#define __MEM_STORGE_H__
#include <stdbool.h>
#include <string.h>
#include <freertos/FreeRTOS.h>
#include <freertos/task.h>
#include "freertos/event_groups.h"
#include "esp_wifi.h"
#include "nvs_flash.h"
#include <freertos/queue.h>

_Bool mem_storge_write(char*, char*, void*, size_t);
_Bool mem_storge_read(char*, char*, void*, size_t);
_Bool mem_storge_is_empty(char*);
void mem_storge_erase_namespace(char*);

#endif