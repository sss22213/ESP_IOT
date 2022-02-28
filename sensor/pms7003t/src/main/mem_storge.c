#include "mem_storge.h"

_Bool mem_storge_write(char *namespace, char *region, void *data, size_t len)
{
    nvs_handle_t handle;
    nvs_open(namespace, NVS_READWRITE, &handle);
    nvs_set_blob(handle, region, data, len);
    nvs_close(handle);

    return true;
}

_Bool mem_storge_read(char *namespace, char *region, void *data, size_t len)
{
    nvs_handle_t handle;
    ESP_ERROR_CHECK(nvs_open(namespace, NVS_READONLY, &handle));
    ESP_ERROR_CHECK(nvs_get_blob(handle, region, data, &len));
    nvs_close(handle);

    return true;
}

_Bool mem_storge_is_empty(char *namespace)
{
    nvs_handle_t handle;
    size_t size_name = 0;
    nvs_open(namespace, NVS_READONLY, &handle);
    nvs_get_used_entry_count(handle, &size_name);
    nvs_close(handle);

    if (size_name < 1) {
        return true;
    } else {
        return false;
    }
}

void mem_storge_erase_namespace(char *namespace)
{
    nvs_handle_t handle;
    nvs_open(namespace, NVS_READONLY, &handle);
    nvs_erase_all(handle);
    nvs_close(handle);
}