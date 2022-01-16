#include "wifi.h"

static EventGroupHandle_t s_wifi_event_group;

enum EVENT {
    CONNECTED_BIT = BIT0,
    ESPTOUCH_DONE_BIT = BIT1
};

static inline void _smart_connect(void *parm)
{
    EventBits_t uxBits;

    smartconfig_start_config_t cfg = SMARTCONFIG_START_CONFIG_DEFAULT();

    esp_smartconfig_set_type(SC_TYPE_ESPTOUCH);

    esp_smartconfig_start(&cfg);

    while (1) {
        uxBits = xEventGroupWaitBits(s_wifi_event_group, CONNECTED_BIT | ESPTOUCH_DONE_BIT, true, false, portMAX_DELAY);
        /*
        if(uxBits & CONNECTED_BIT) {
            //printf("WiFi Connected to ap\n");
        }
        */

        if(uxBits & ESPTOUCH_DONE_BIT) {
            esp_smartconfig_stop();
            vTaskDelay(200 / portTICK_RATE_MS);
            esp_restart();
            vTaskDelete(NULL);
        }
    }
}


static void event_handler(void* arg, esp_event_base_t event_base, int32_t event_id, void* event_data)
{
    smartconfig_event_got_ssid_pswd_t *evt = NULL;

    wifi_config_t wifi_config;

    if (event_base == WIFI_EVENT && event_id == WIFI_EVENT_STA_START) {
        
        if (mem_storge_is_empty(WIFI_NAMESPACE) == false) {
            esp_wifi_disconnect();
            mem_storge_read(WIFI_NAMESPACE, WIFI_REGION, &wifi_config, sizeof(wifi_config_t));
            esp_wifi_set_config(WIFI_IF_STA, &wifi_config);
            esp_wifi_connect();
        }
        
    } else if (event_base == WIFI_EVENT && event_id == WIFI_EVENT_STA_DISCONNECTED) {
        xTaskCreate(_smart_connect, "wifi_smart_connect_task", 4096, NULL, 3, NULL);
        xEventGroupClearBits(s_wifi_event_group, CONNECTED_BIT);

    } else if (event_base == IP_EVENT && event_id == IP_EVENT_STA_GOT_IP) {
        xEventGroupSetBits(s_wifi_event_group, CONNECTED_BIT);

    } else if (event_base == SC_EVENT && event_id == SC_EVENT_SCAN_DONE) {
        printf("Scan done\n");

    } else if (event_base == SC_EVENT && event_id == SC_EVENT_FOUND_CHANNEL) {
        printf("Found channels\n");

    } else if (event_base == SC_EVENT && event_id == SC_EVENT_GOT_SSID_PSWD) {
        evt = (smartconfig_event_got_ssid_pswd_t *)event_data;
        memset(&wifi_config, 0, sizeof(wifi_config_t));

        memcpy(&wifi_config.sta.ssid, evt->ssid, sizeof(wifi_config.sta.ssid));
        memcpy(&wifi_config.sta.password, evt->password, sizeof(wifi_config.sta.password));
        if (wifi_config.sta.bssid_set == true) {
            memcpy(wifi_config.sta.bssid, evt->bssid, sizeof(wifi_config.sta.bssid));
        }

        esp_wifi_disconnect();
        esp_wifi_set_config(WIFI_IF_STA, &wifi_config);
        esp_wifi_connect();

        mem_storge_write(WIFI_NAMESPACE, WIFI_REGION, &wifi_config, sizeof(wifi_config_t));

    } else if (event_base == SC_EVENT && event_id == SC_EVENT_SEND_ACK_DONE) {
        xEventGroupSetBits(s_wifi_event_group, ESPTOUCH_DONE_BIT);
    }

}

_Bool wifi_initialize(void)
{
    wifi_init_config_t cfg = WIFI_INIT_CONFIG_DEFAULT();

    s_wifi_event_group = xEventGroupCreate();

    esp_netif_create_default_wifi_sta();

    esp_wifi_init(&cfg);

    esp_wifi_set_mode(WIFI_MODE_STA);

    esp_event_handler_register(WIFI_EVENT, ESP_EVENT_ANY_ID, &event_handler, NULL);
    esp_event_handler_register(IP_EVENT, IP_EVENT_STA_GOT_IP, &event_handler, NULL);
    esp_event_handler_register(SC_EVENT, ESP_EVENT_ANY_ID, &event_handler, NULL);

    esp_wifi_start();

    return true;
}