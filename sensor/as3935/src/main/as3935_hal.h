#ifndef __AS3935_HAL_H__
#define __AS3935_HAL_H__
#include <stdint.h>
#include <stdbool.h>
#include "esp_system.h"
#include "driver/spi_master.h"

_Bool as3935_write_reg(uint8_t, uint8_t, uint8_t);
_Bool as3935_read_reg(uint8_t, uint8_t*, uint8_t);

#endif