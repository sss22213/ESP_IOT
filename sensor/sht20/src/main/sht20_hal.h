#ifndef __SHT20_HAL_H__
#define __SHT20_HAL_H__
#include <stdbool.h>
#include <stdint.h>
#include "esp_system.h"
#include "driver/i2c.h"

#define I2C_NUM I2C_NUM_0

// 100k
#define SHT20_IIC_SPEED 100000

_Bool sht20_iic_initial(int, int);

_Bool sht20_iic_mem_write_byte(uint8_t, uint8_t, uint8_t*, uint16_t);

_Bool sht20_iic_mem_read_byte(uint8_t, uint8_t, uint8_t*, uint16_t);

_Bool sht20_iic_hold_read(uint8_t, uint8_t, uint8_t*, uint16_t, int);


#endif