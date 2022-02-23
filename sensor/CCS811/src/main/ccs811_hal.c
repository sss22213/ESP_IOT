#include "ccs811_hal.h"

_Bool ccs811_iic_initial(int sda_pin, int scl_pin)
{
   esp_err_t err = ESP_OK;

    i2c_config_t i2c_config_tmp = {
        .mode = I2C_MODE_MASTER,
        .sda_io_num = sda_pin,
        .sda_pullup_en = GPIO_PULLUP_ENABLE,
        .scl_io_num = scl_pin, 
        .scl_pullup_en = GPIO_PULLUP_ENABLE,
        .master.clk_speed = CCS881_IIC_SPEED,
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

_Bool ccs811_iic_mem_write_reg(uint8_t mem_address)
{
    i2c_cmd_handle_t i2c_cmd = i2c_cmd_link_create();

    i2c_master_start(i2c_cmd);
    i2c_master_write_byte(i2c_cmd, (CCS811_SLAVE_ADDRESS << 1) | I2C_MASTER_WRITE, I2C_MASTER_ACK);
    i2c_master_write(i2c_cmd, &mem_address, 1, I2C_MASTER_ACK);
    i2c_master_stop(i2c_cmd);
    i2c_master_cmd_begin(I2C_NUM_0, i2c_cmd, 20 / portTICK_RATE_MS);
    i2c_cmd_link_delete(i2c_cmd);

    return true;
}

_Bool ccs811_iic_mem_write_byte(uint8_t mem_address, uint8_t *write_data, uint8_t data_len)
{
    i2c_cmd_handle_t i2c_cmd = i2c_cmd_link_create();

    i2c_master_start(i2c_cmd);
    i2c_master_write_byte(i2c_cmd, (CCS811_SLAVE_ADDRESS << 1) | I2C_MASTER_WRITE, I2C_MASTER_ACK);
    i2c_master_write_byte(i2c_cmd, mem_address, I2C_MASTER_ACK);
    i2c_master_write(i2c_cmd, write_data, data_len, I2C_MASTER_ACK);
    i2c_master_stop(i2c_cmd);
    i2c_master_cmd_begin(I2C_NUM_0, i2c_cmd, 20 / portTICK_RATE_MS);
    i2c_cmd_link_delete(i2c_cmd);

    return true;
}

_Bool ccs811_iic_mem_read_byte(uint8_t mem_address, uint8_t *read_data, uint8_t data_len)
{
    i2c_cmd_handle_t i2c_cmd = i2c_cmd_link_create();

    esp_err_t err;

    i2c_master_start(i2c_cmd);
    i2c_master_write_byte(i2c_cmd, (CCS811_SLAVE_ADDRESS << 1) | I2C_MASTER_WRITE, I2C_MASTER_ACK);
    i2c_master_write_byte(i2c_cmd, 0x20, I2C_MASTER_ACK);
    i2c_master_stop(i2c_cmd);
    printf("%s\n", esp_err_to_name(i2c_master_cmd_begin(I2C_NUM_0, i2c_cmd, 1000/portTICK_RATE_MS)));
    i2c_cmd_link_delete(i2c_cmd);

    i2c_cmd = i2c_cmd_link_create();
    i2c_master_start(i2c_cmd);
    i2c_master_write_byte(i2c_cmd, (CCS811_SLAVE_ADDRESS << 1) | I2C_MASTER_READ, I2C_MASTER_ACK);
    i2c_master_read_byte(i2c_cmd, read_data, I2C_MASTER_NACK);
    i2c_master_stop(i2c_cmd);
    /*
    i2c_master_write_byte(i2c_cmd, (CCS811_SLAVE_ADDRESS << 1) | 0, I2C_MASTER_ACK);
    i2c_master_write_byte(i2c_cmd, mem_address, I2C_MASTER_ACK);

    if (data_len == 1) {
        i2c_master_start(i2c_cmd);
        i2c_master_write_byte(i2c_cmd, (CCS811_SLAVE_ADDRESS << 1) | 1, I2C_MASTER_ACK);
        i2c_master_read(i2c_cmd, read_data, 1, I2C_MASTER_NACK);
        i2c_master_stop(i2c_cmd);
    } else {
        for (int iic_idx = 0; iic_idx < data_len; iic_idx+=2) {
            i2c_master_start(i2c_cmd);
            i2c_master_write_byte(i2c_cmd, (CCS811_SLAVE_ADDRESS << 1) | 1, I2C_MASTER_ACK);
            i2c_master_read(i2c_cmd, read_data+iic_idx, 2, I2C_MASTER_ACK);
            i2c_master_stop(i2c_cmd);
        }
    }
    */

    printf("%s\n", esp_err_to_name(i2c_master_cmd_begin(I2C_NUM_0, i2c_cmd, 1000/portTICK_RATE_MS)));

    printf("0x%x\n", *read_data);

    i2c_cmd_link_delete(i2c_cmd);

    return true;
}