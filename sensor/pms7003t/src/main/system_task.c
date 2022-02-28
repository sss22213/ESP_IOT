#include "system_task.h"

void system_task_process(void *argument)
{
    EventBits_t event_bit = xEventGroupGetBits(xsystemEventGroup);

    while (1) {
        event_bit = xEventGroupGetBits(xsystemEventGroup);

        switch (event_bit) {
        case SYSTEM_RESET:

            break;

        case SYSTEM_REBOOT:
            esp_restart();
            break;
        }
        vTaskDelay(300 / portTICK_RATE_MS);
    }
}