#include "sht20_hal.h"

_Bool sht20_iic_initial(int scl_pin, int sda_pin)
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

_Bool sht20_iic_hold_read(uint8_t slave_address, uint8_t mem_address, uint8_t *read_byte, uint16_t len, int time_delay_ms)
{
    i2c_cmd_handle_t i2c_cmd = i2c_cmd_link_create();

    i2c_master_start(i2c_cmd);
    i2c_master_write_byte(i2c_cmd, (slave_address << 1) | 0, I2C_MASTER_ACK);
    i2c_master_write_byte(i2c_cmd, mem_address, I2C_MASTER_ACK);
    i2c_master_stop(i2c_cmd);
    i2c_master_cmd_begin(I2C_NUM_0, i2c_cmd, 1 / portTICK_RATE_MS); 
    i2c_cmd_link_delete(i2c_cmd);
    vTaskDelay(time_delay_ms / portTICK_RATE_MS);

    i2c_cmd = i2c_cmd_link_create();
    i2c_master_start(i2c_cmd);
    i2c_master_write_byte(i2c_cmd, (slave_address << 1) | 1, I2C_MASTER_NACK);
    i2c_master_stop(i2c_cmd);
    i2c_master_cmd_begin(I2C_NUM_0, i2c_cmd, 0);
    i2c_cmd_link_delete(i2c_cmd);
    vTaskDelay(time_delay_ms / portTICK_RATE_MS);

    i2c_cmd = i2c_cmd_link_create();
    i2c_master_start(i2c_cmd);
    i2c_master_write_byte(i2c_cmd, (slave_address << 1) | 1, I2C_MASTER_ACK);
    i2c_master_read(i2c_cmd, read_byte, len, I2C_MASTER_ACK);
    i2c_master_stop(i2c_cmd);
    i2c_master_cmd_begin(I2C_NUM_0, i2c_cmd, 0);
    i2c_cmd_link_delete(i2c_cmd);

    return true;
}


_Bool sht20_iic_mem_write_byte(uint8_t slave_address, uint8_t mem_address, uint8_t *write_byte, uint16_t len)
{
    i2c_cmd_handle_t i2c_cmd = i2c_cmd_link_create();

    i2c_master_start(i2c_cmd);
    i2c_master_write_byte(i2c_cmd, (slave_address << 1) | 0, I2C_MASTER_ACK);
    i2c_master_write_byte(i2c_cmd, mem_address, I2C_MASTER_ACK);
    i2c_master_write(i2c_cmd, write_byte, len, I2C_MASTER_ACK);
    i2c_master_stop(i2c_cmd);
    i2c_master_cmd_begin(I2C_NUM_0, i2c_cmd, 20 / portTICK_RATE_MS);
    i2c_cmd_link_delete(i2c_cmd);

    return true;
}

_Bool sht20_iic_mem_read_byte(uint8_t slave_address, uint8_t mem_address, uint8_t *read_byte, uint16_t len)
{
    int res = 0;
    i2c_cmd_handle_t i2c_cmd = i2c_cmd_link_create();

    // Config i2c stretch
    i2c_set_timeout(I2C_NUM_0, 100);
    i2c_master_start(i2c_cmd);
    i2c_master_write_byte(i2c_cmd, (slave_address << 1) | 0, I2C_MASTER_ACK);
    i2c_master_write_byte(i2c_cmd, mem_address, I2C_MASTER_ACK);
    i2c_master_stop(i2c_cmd);
    i2c_master_start(i2c_cmd);
    i2c_master_write_byte(i2c_cmd, (slave_address << 1 | 1), I2C_MASTER_ACK);
    i2c_master_read(i2c_cmd, read_byte, len, I2C_MASTER_ACK);
    i2c_master_stop(i2c_cmd);
    i2c_master_cmd_begin(I2C_NUM_0, i2c_cmd, 100 / portTICK_RATE_MS);
    i2c_cmd_link_delete(i2c_cmd);

    return true;
}