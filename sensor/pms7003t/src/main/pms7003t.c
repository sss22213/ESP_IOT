#include "pms7003t.h"

pms7003t_data *pms7003t_initial(uint8_t uart_num)
{
    //
    pms7003t_queue = xQueueCreate(10, sizeof(pms7003t_data));
    // initial PMSS7003T (N81)
    uart_config_t uart_config = {
        .baud_rate = 9600,
        .data_bits = UART_DATA_8_BITS,
        .parity = UART_PARITY_DISABLE,
        .stop_bits = UART_STOP_BITS_1,
        .flow_ctrl = UART_HW_FLOWCTRL_DISABLE,
    };
    ESP_ERROR_CHECK(uart_param_config(uart_num, &uart_config));
    const int uart_buffer_size = (1024 * 2);
    ESP_ERROR_CHECK(uart_driver_install(uart_num, uart_buffer_size, uart_buffer_size, 10, &uart_queue, 0));
    // set pin
    ESP_ERROR_CHECK(uart_set_pin(uart_num, 17, 16, 22, 38));
    pms7003t_data *new_pms7003t_data = (pms7003t_data*)calloc(1, sizeof(pms7003t_data));
    new_pms7003t_data->uart_num = uart_num;
    return new_pms7003t_data;
};

void pms7003t_read(pms7003t_data* pms7003t_data_obj)
{
    uint8_t data[128];
    int length = 0;
    ESP_ERROR_CHECK(uart_get_buffered_data_len(pms7003t_data_obj->uart_num, (size_t*)&length));
    length = uart_read_bytes(pms7003t_data_obj->uart_num, data, length, 100);

    // chechsum
    uint16_t checksum = 0x42 + 0x4d;
    for(int idx = 2; idx < 30; idx++){
        checksum += data[idx];
    }
    if(checksum != ((data[30] << 8) | data[31])){
        return;
    }

    // data 
    pms7003t_data_obj->PM1_0 = (data[10] << 8) | data[11];
    pms7003t_data_obj->PM2_5 = (data[12] << 8) | data[13];
    pms7003t_data_obj->PM10 = (data[14] << 8) | data[15];
    pms7003t_data_obj->temperature = ((data[24] << 8) | data[25]) / 10.0;
    pms7003t_data_obj->humidity = ((data[26] << 8) | data[27]) / 10.0;
    xQueueSend(pms7003t_queue, pms7003t_data_obj, 500 / portTICK_RATE_MS);
};