#include "mqtt.h"

enum MQTT_EVENT {
    CONNECTED_MQTT_BROKEN_BIT = BIT0,
};

// MQTT signal
static EventGroupHandle_t s_mqtt_event_group;

static void mqtt_event_handler(void *handler_args, esp_event_base_t base, int32_t event_id, void *event_data)
{
    //esp_mqtt_event_handle_t event = event_data;
    //esp_mqtt_client_handle_t client = event->client;
    //int msg_id;
    switch ((esp_mqtt_event_id_t)event_id) {
    case MQTT_EVENT_CONNECTED:
        xEventGroupSetBits(s_mqtt_event_group, CONNECTED_MQTT_BROKEN_BIT);
        printf("Already connect to mqtt broken\n");
        break;
    case MQTT_EVENT_DISCONNECTED:
        xEventGroupClearBits(s_mqtt_event_group, CONNECTED_MQTT_BROKEN_BIT);
        break;
    case MQTT_EVENT_SUBSCRIBED:
        printf("Detect EVENT\n");
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

static inline void _init(esp_mqtt_client_config_t mqtt_cfg)
{
    const esp_mqtt_client_config_t mqtt_cfg1 = {
        .uri = mqtt_cfg.uri,
    };

    esp_mqtt_client_handle_t client = esp_mqtt_client_init(&mqtt_cfg1);

    esp_mqtt_client_register_event(client, ESP_EVENT_ANY_ID, mqtt_event_handler, client);

    esp_mqtt_client_start(client);
}

void mqtt_init(const char *uri)
{
    esp_mqtt_client_config_t mqtt_cfg;

    s_mqtt_event_group = xEventGroupCreate();

    mqtt_cfg.uri = uri;

    _init(mqtt_cfg);
}

void mqtt_wait_connect_loop(void)
{
    EventBits_t connect_bit = xEventGroupGetBits(s_mqtt_event_group);

    while ((connect_bit & CONNECTED_MQTT_BROKEN_BIT) != CONNECTED_MQTT_BROKEN_BIT) {
        connect_bit = xEventGroupGetBits(s_mqtt_event_group);
        vTaskDelay(1000 / portTICK_RATE_MS);
    }
}