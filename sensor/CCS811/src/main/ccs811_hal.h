#ifndef __CCS811_HAL_H__
#define __CCS811_HAL_H__
#include <stdint.h>
#include <stdbool.h>
#include "esp_system.h"
#include "driver/i2c.h"

#define CCS811_SLAVE_ADDRESS 0x5A
#define I2C_NUM I2C_NUM_0

// 100k
#define CCS881_IIC_SPEED 100000

_Bool ccs811_iic_initial(int, int);

_Bool ccs811_iic_mem_write_byte(uint8_t, uint8_t*, uint8_t);

_Bool ccs811_iic_mem_read_byte(uint8_t, uint8_t*, uint8_t);

_Bool ccs811_iic_mem_write_reg(uint8_t);

#endif