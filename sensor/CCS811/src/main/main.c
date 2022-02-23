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
#include "ccs811.h"

struct _ccs811_device *ptr_ccs811_device;

void main_task(void *argument)
{
   while (1) {
      vTaskDelay(500 / portTICK_RATE_MS);
   }
}

void ccs811_tvoc(void *argument)
{
   uint16_t tvoc;

   while (1) {
      ccs811_read_tvoc(ptr_ccs811_device, &tvoc);
      printf("%d\n", tvoc);
      //mqtt_publish("CCS811_TVOC", SENSOR_EVENT, tvoc);
      vTaskDelay(500 / portTICK_RATE_MS);
   }
}

/*
void sht20_temperature_humidity(void *argument)
{
   while (1) {
      sht20_read_temperature(ptr_sht20);
      sht20_read_humidity(ptr_sht20);
      mqtt_publish("SHT20_Temperature", SENSOR_EVENT, ptr_sht20->temperature);
      mqtt_publish("SHT20_Humidity", SENSOR_EVENT, ptr_sht20->humidity);
      //printf("%e %e\n", ptr_sht20->temperature, ptr_sht20->humidity);
      vTaskDelay(500 / portTICK_RATE_MS);
   }
}
*/

void app_main(void)
{
   INIT_CCS811(ccs811_device, 22, 21);
   ptr_ccs811_device = &ccs811_device;

   nvs_flash_init();
   esp_netif_init();
   esp_event_loop_create_default();

   wifi_initialize();
   wifi_wait_connect_loop();

   mqtt_initialize(MQTT_BROKEN_URI);
   mqtt_wait_connect_loop();

   xTaskCreate(main_task, "main_task", 6 * 1024, NULL, 5, NULL);
   xTaskCreate(system_task_process, "system_task_process", 6 * 1024, NULL, 7, NULL);
   //xTaskCreate(ccs811_tvoc, "ccs811_tvoc", 6 * 1024, NULL, 4, NULL);
}
