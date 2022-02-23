#include "as3935_hal.h"

spi_device_handle_t spi;

_Bool as3935_spi_initial(void)
{
    spi_bus_config_t buscfg = {
        .miso_io_num=PIN_NUM_MISO,
        .mosi_io_num=PIN_NUM_MOSI,
        .sclk_io_num=PIN_NUM_CLK,
        .intr_flags=ESP_INTR_FLAG_IRAM,
        .quadwp_io_num=-1,
        .quadhd_io_num=-1,
        .max_transfer_sz=SOC_SPI_MAXIMUM_BUFFER_SIZE
    };

    //CPOL = 0, CPHA = 0, 2Mhz
    spi_device_interface_config_t devcfg = { 
        .clock_speed_hz = 2*1000*1000,
        .mode=0,
        .spics_io_num=PIN_NUM_CS,
        .queue_size=7,
        .command_bits = 0,  // 0-16
        .address_bits = 0,  // 0-64
        .dummy_bits = 0,
        .duty_cycle_pos = 128,  // default: 128
        .input_delay_ns = 0,
        .flags = 0,
        .pre_cb = NULL,
        .post_cb = NULL,
    };

    /*
    gpio_config_t io_conf={
        .intr_type=GPIO_INTR_POSEDGE,
        .mode=GPIO_MODE_OUTPUT,
        .pin_bit_mask=(1 << PIN_NUM_INT)
    };
    */

    //gpio_config(&io_conf);

    /*

    gpio_set_pull_mode(PIN_NUM_MOSI, GPIO_PULLUP_ONLY);

    gpio_set_pull_mode(PIN_NUM_CLK, GPIO_PULLUP_ONLY);

    gpio_set_pull_mode(PIN_NUM_CS, GPIO_PULLUP_ONLY);
    */

    ESP_ERROR_CHECK(spi_bus_initialize(AS3935_SPI_HOST, &buscfg, 0));

    ESP_ERROR_CHECK(spi_bus_add_device(AS3935_SPI_HOST, &devcfg, &spi));

    return true;
}

_Bool as3935_write_reg(uint8_t reg_address, uint8_t data, uint8_t len)
{
    struct spi_transaction_t spi_transaction;

    spi_transaction.flags = SPI_TRANS_USE_TXDATA;
    spi_transaction.tx_data[0] = reg_address | (0 << 6);
    spi_transaction.tx_data[1] = data;
    spi_transaction.length = 16;

    spi_device_transmit(spi, &spi_transaction);

    return true;
}

_Bool as3935_read_reg(uint8_t reg_address, uint8_t *data, uint8_t len)
{
    spi_device_acquire_bus(spi, portMAX_DELAY);

    uint8_t reg_d = reg_address | (1 << 6);

    uint16_t data_16 = 0;
    
    spi_transaction_t tM = {
        .tx_buffer = &reg_d,
        .rx_buffer = &data_16,
        .length = 16,
        .rxlength = 16,
    };
    
    
    spi_device_transmit(spi, &tM);
    spi_device_release_bus(spi);
/*
    spi_device_acquire_bus(spi, portMAX_DELAY);
    spi_device_transmit(spi, &tM);
    spi_device_release_bus(spi);
    */

    printf("%d\n", data_16);

    /*
    uint16_t res = SPI_SWAP_DATA_RX(data_16, 16);

    printf("%d %d\n", data_16, res);
    
    struct spi_transaction_t spi_transaction;
    struct spi_transaction_t spi_transaction1;

    uint8_t rx_buff[1024] = {0};

    spi_transaction.flags = SPI_TRANS_USE_TXDATA;
    spi_transaction.tx_data[0] = reg_address | (1 << 6);
    spi_transaction.length = 16;
    spi_transaction.rxlength = 16;


    ESP_ERROR_CHECK(spi_device_polling_transmit(spi, &spi_transaction));

    
    spi_transaction1.flags = SPI_TRANS_USE_RXDATA;
    spi_transaction1.rxlength = 16;
    spi_transaction1.length = 16;
    spi_transaction1.rx_buffer = rx_buff;
    ESP_ERROR_CHECK(spi_device_polling_transmit(spi, &spi_transaction1));
    
    

    //printf("%d\n", spi_transaction.rx_data[0]);

    
    memcpy(data, spi_transaction.rx_data, sizeof(data[0])*1);
    */

    return true;
}