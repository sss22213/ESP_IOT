#include "mqtt.h"

enum MQTT_EVENT {
    CONNECTED_MQTT_BROKEN_BIT = BIT0,
};

// MQTT signal
static EventGroupHandle_t s_mqtt_event_group;

static esp_mqtt_client_handle_t client;

static QueueHandle_t system_message_queue;

static void mqtt_event_handler(void *handler_args, esp_event_base_t base, int32_t event_id, void *event_data)
{
    //esp_mqtt_event_handle_t event = event_data;
    //esp_mqtt_client_handle_t client = event->client;
    //int msg_id;
    esp_mqtt_event_handle_t event = event_data;

    char data_buf[1024] = {0};

    struct _message message;

    switch ((esp_mqtt_event_id_t)event_id) {
    case MQTT_EVENT_CONNECTED:
        xEventGroupSetBits(s_mqtt_event_group, CONNECTED_MQTT_BROKEN_BIT);
        printf("Already connect to mqtt broken\n");
        esp_mqtt_client_subscribe(client, "SHT20_Temperature", 0);
        esp_mqtt_client_subscribe(client, "SYSTEM", 0);
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
        memset(data_buf, 0, sizeof(data_buf));
        memcpy(data_buf, event->data, event->data_len);
        data_buf[event->data_len] = '\0';
        /*
        printf("%s\n", data_buf);
        */
        //printf("DATA\n");
        message_unpack(&message, data_buf);
        //printf("%d\n", message.type);
        mqtt_event_process(message.type, message);
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

    client = esp_mqtt_client_init(&mqtt_cfg1);

    system_message_queue = xQueueCreate(100, sizeof(struct _mqtt_event_inform_message));

    esp_mqtt_client_register_event(client, ESP_EVENT_ANY_ID, mqtt_event_handler, client);

    mqtt_event_init();

    esp_mqtt_client_start(client);
}

void mqtt_initialize(const char *uri)
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
/**
 * {"NAME":<name>,"TYPE":<type>,"VALUE":<value>,"TIMESTAMP":<timestamp>,"PID":<pid>,"VID":<vid>,"UUID":<UUID>}
 */
void mqtt_publish(char *name, int type, float value)
{
    struct _mqtt_event_inform_message mqtt_event_inform_message;
    memset(&mqtt_event_inform_message, 0, sizeof(mqtt_event_inform_message));

    char raw_message[512] = {0};

    // Waiting for timestamp
    while (mqtt_event_inform_message.event_id != TIMESTAMP_EVENT) {
        if (xQueueReceive(mqtt_subscribe_queue, &(mqtt_event_inform_message), 100 / portTICK_RATE_MS) != pdPASS) {
            mqtt_event_inform_message.event_id = 0;
        }
    }

    message_pack(name, type, value, 0, mqtt_event_inform_message.i_value, PID, VID, UUID, raw_message);

    esp_mqtt_client_publish(client, name, raw_message, 0, 0, 0);
}