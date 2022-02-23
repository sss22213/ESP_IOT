#ifndef __AS3935_HAL_H__
#define __AS3935_HAL_H__
#include <stdint.h>
#include <stdbool.h>
#include <string.h>
#include "esp_system.h"
#include "driver/spi_master.h"
#include "driver/gpio.h"

#define PIN_NUM_MISO 19 
#define PIN_NUM_MOSI 23
#define PIN_NUM_CLK 18
#define PIN_NUM_CS 5
#define PIN_NUM_INT 4

#define AS3935_SPI_HOST SPI3_HOST

_Bool as3935_spi_initial(void);
_Bool as3935_write_reg(uint8_t, uint8_t, uint8_t);
_Bool as3935_read_reg(uint8_t, uint8_t*, uint8_t);

#endif