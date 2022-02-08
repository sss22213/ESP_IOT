#include "ccs811_hal.h"

void ccs811_iic_initial(int sda_pin, int scl_pin)
{
   esp_err_t err = ESP_OK;

    i2c_config_t i2c_config_tmp = {
        .mode = I2C_MODE_MASTER,
        .sda_io_num = sda_pin,
        .sda_pullup_en = GPIO_PULLUP_ENABLE,
        .scl_io_num = scl_pin, 
        .scl_pullup_en = GPIO_PULLUP_ENABLE,
        .master.clk_speed = SHT20_IIC_SPEED,
    };

    err = i2c_param_config(I2C_NUM_0, &i2c_config_tmp);
    if(err != ESP_OK){
        return false;
    }

    err = i2c_driver_install(I2C_NUM_0, I2C_MODE_MASTER, 0 ,0, 0);
    if(err != ESP_OK){
        return false;
    }

    return true;
}

_Bool ccs811_iic_mem_write_byte(uint8_t mem_address, uint8_t *write_datam, uint8_t data_len)
{
    
}

_Bool ccs811_iic_mem_read_byte(uint8_t mem_address, uint8_t *read_data, uint8_t data_len)
{

}