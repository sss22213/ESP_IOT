#include "as3935_hal.h"

static spi_device_handle_t spi;

_Bool as3935_spi_initial(void)
{
    spi_bus_config_t buscfg = {
        .miso_io_num=PIN_NUM_MISO,
        .mosi_io_num=PIN_NUM_MOSI,
        .sclk_io_num=PIN_NUM_CLK,
        .quadwp_io_num=-1,
        .quadhd_io_num=-1,
    };

    //CPOL = 0, CPHA = 0, 2Mhz
    spi_device_interface_config_t devcfg = { 
        .clock_speed_hz = 2*1000*1000,
        .mode=0,
        .spics_io_num=PIN_NUM_CS
    };

    spi_bus_initialize(AS3935_SPI_HOST, &buscfg, SPI_DMA_CH_AUTO);

    spi_bus_add_device(AS3935_SPI_HOST, &devcfg, &spi);

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
    struct spi_transaction_t spi_transaction;

    spi_transaction.flags = SPI_TRANS_USE_TXDATA;
    spi_transaction.tx_data[0] = reg_address | (1 << 6);
    spi_transaction.length = 16;

    spi_device_transmit(spi, &spi_transaction);

    spi_transaction.flags = SPI_TRANS_USE_RXDATA;
    spi_device_transmit(spi, &spi_transaction);

    memcpy(data, spi_transaction.rx_data, sizeof(data[0])*1);

    return true;
}