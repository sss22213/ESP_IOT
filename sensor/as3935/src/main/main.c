/*
   This example code is in the Public Domain (or CC0 licensed, at your option.)

   Unless required by applicable law or agreed to in writing, this
   software is distributed on an "AS IS" BASIS, WITHOUT WARRANTIES OR
   CONDITIONS OF ANY KIND, either express or implied.
*/
#include <stdio.h>
#include "sdkconfig.h"
#include "freertos/FreeRTOS.h"
#include "freertos/task.h"
#include "esp_system.h"
#include "esp_spi_flash.h"
#include "device_info.h"
#include "mqtt.h"
#include "wifi.h"
#include "system_task.h"
#include "as3935.h"

struct _as3935_device *ptr_as3935_device;

void main_task(void *argument)
{
   while (1) {
      vTaskDelay(500 / portTICK_RATE_MS);
   }
}


void read_lightning(void *argument)
{
   while (1) {
      as3935_get_lightning_distance(ptr_as3935_device);
      //printf("%d\n", ptr_as3935_device->as3935_reg.as3935_reg_table_byte.as3935_reg_table_loc_7.DISTANCE);
      //mqtt_publish("AS3935_LIGHTNING", SENSOR_EVENT, ptr_as3935_device->as3935_reg.as3935_reg_table_byte.as3935_reg_table_loc_7.DISTANCE);
      vTaskDelay(1000 / portTICK_RATE_MS);
   }
}


void app_main(void)
{
   nvs_flash_init();
   esp_netif_init();
   //esp_event_loop_create_default();

   /*
   wifi_initialize();
   wifi_wait_connect_loop();

   mqtt_initialize(MQTT_BROKEN_URI);
   mqtt_wait_connect_loop();
   */

   INIT_AS3935_DEVICE(as3935_struct);
   ptr_as3935_device = &as3935_struct;

   xTaskCreate(main_task, "main_task", 6 * 1024, NULL, 5, NULL);
   //xTaskCreate(system_task_process, "system_task_process", 6 * 1024, NULL, 7, NULL);
   xTaskCreate(read_lightning, "read_lightning", 6 * 1024, NULL, 4, NULL);
}
