/* Hello World Example

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
#include "sht20.h"
#include "wifi.h"
struct _sht20 *ptr_sht20;

void main_task(void *argument)
{
   while (1) {
      vTaskDelay(500 / portTICK_RATE_MS);
   }
}

void sht20_temperature(void *argument)
{
   while (1) {
      sht20_read_temperature(ptr_sht20);
      sht20_read_humidity(ptr_sht20);
     
      vTaskDelay(500 / portTICK_RATE_MS);
   }
}

void app_main(void)
{

   INIT_SHT20(sht20_device, 22, 21);
   ptr_sht20 = &sht20_device;
   nvs_flash_init();
   esp_netif_init();
   esp_event_loop_create_default();
   wifi_initialize();

   xTaskCreate(main_task, "main_task", 6 * 1024, NULL, 5, NULL);
   //xTaskCreate(sht20_temperature, "sht20_temperature", 6 * 1024, NULL, 7, NULL);
}
