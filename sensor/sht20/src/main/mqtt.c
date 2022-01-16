#include "mqtt.h"

static void mqtt_event_handler(void *handler_args, esp_event_base_t base, int32_t event_id, void *event_data)
{
    //esp_mqtt_event_handle_t event = event_data;
    //esp_mqtt_client_handle_t client = event->client;
    //int msg_id;
    switch ((esp_mqtt_event_id_t)event_id) {
    case MQTT_EVENT_CONNECTED:
 
        break;
    case MQTT_EVENT_DISCONNECTED:
 
        break;
    case MQTT_EVENT_SUBSCRIBED:

        break;
    case MQTT_EVENT_UNSUBSCRIBED:

        break;
    case MQTT_EVENT_PUBLISHED:

        break;
    case MQTT_EVENT_DATA:

        break;
    case MQTT_EVENT_ERROR:

        break;
    default:
        
        break;
    }
}

void mqtt_init(esp_mqtt_client_config_t mqtt_cfg)
{
    esp_mqtt_client_handle_t client = esp_mqtt_client_init(&mqtt_cfg);
    esp_mqtt_client_register_event(client, ESP_EVENT_ANY_ID, mqtt_event_handler, client);
    esp_mqtt_client_start(client);
}