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
#include "pms7003t.h"
#include "system_task.h"

void main_task(void *argument)
{
   while (1) {
      vTaskDelay(500 / portTICK_RATE_MS);
   }
}

void pms7003t_air_quility(void *argument)
{
   pms7003t_data *new_pms7003t_data = pms7003t_initial(2);
   while (1) {
      pms7003t_read(new_pms7003t_data);
      mqtt_publish("PMS7003T_PM1_0", SENSOR_EVENT, new_pms7003t_data->PM1_0);
      mqtt_publish("PMS7003T_PM2_5", SENSOR_EVENT, new_pms7003t_data->PM2_5);
      mqtt_publish("PMS7003T_PM10", SENSOR_EVENT, new_pms7003t_data->PM10);
      vTaskDelay(500 / portTICK_RATE_MS);
   }
}

void app_main(void)
{
   nvs_flash_init();
   esp_netif_init();
   esp_event_loop_create_default();

   wifi_initialize();
   wifi_wait_connect_loop();

   mqtt_initialize(MQTT_BROKEN_URI);
   mqtt_wait_connect_loop();

   xTaskCreate(main_task, "main_task", 6 * 1024, NULL, 5, NULL);
   xTaskCreate(system_task_process, "system_task_process", 6 * 1024, NULL, 7, NULL);
   xTaskCreate(pms7003t_air_quility, "pms7003t_air_quility", 6 * 1024, NULL, 4, NULL);
}
