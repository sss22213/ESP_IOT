#ifndef __SHT20_H__
#define __SHT20_H__
#include <stdint.h>
#include <stdio.h>
#include <string.h>
#include <stdbool.h>
#include "esp_system.h"
#include "driver/i2c.h"
#include "sht20_hal.h"

#define SHT20_SLAVE_ADDRESS 0x40

#define SHT20_RESET_COMMAND 0xFE
#define SHT20_TRIGER_TEMPERATURE_MEASURE_NO_HOLD_COMMAND  0xF3
#define SHT20_TRIGER_HUMIDITY_MEASURE_NO_HOLD_COMMAND  0xF5
#define SHT20_USER_REGISTER 0xF6

#define SHT20_STATUS_BIT    6
#define SHT20_ON_CHIP_HEATER_BIT    2
#define SHT20_OTP_RELOAD_BIT    1

#define INIT_SHT20(SHT20_NAME, SCL_PIN, SDA_PIN) \
                    struct _sht20 (SHT20_NAME); \
                    sht20_init(&(SHT20_NAME), (SCL_PIN), (SDA_PIN));
                    
typedef enum {
    _SHT20_RESOLUTION_RH_12_T_14,
    _SHT20_RESOLUTION_RH_8_T_12,
    _SHT20_RESOLUTION_RH_10_T_13,
    _SHT20_RESOLUTION_RH_11_T_11,
} _SHT20_RESOLUTION_CONFIG;

typedef enum {
    _SHT20_STATUS_VDD_UP_2V25,
    _SHT20_STATUS_VDD_DOWN_2V25,
} _SHT20_STATUS_CONFIG;

typedef enum {
    _SHT20_ON_CHIP_HEATER_DISABLE,
    _SHT20_ON_CHIP_HEATER_ENABLE,
} _SHT20_ON_CHIP_HEATER_CONFIG;

typedef enum {
    _SHT20_OTP_RELOAD_ENABLE,
    _SHT20_OTP_RELOAD_DISABLE,
} _SHT20_OTP_RELOAD_CONFIG;

struct _sht20_sensor_config {
    _SHT20_RESOLUTION_CONFIG sht20_resolution_config;
    _SHT20_STATUS_CONFIG sht20_status_config;
    _SHT20_ON_CHIP_HEATER_CONFIG sht20_on_chip_heater_config;
    _SHT20_OTP_RELOAD_CONFIG sht20_otp_reload_config;
};

struct _sht20 {
    struct _sht20_sensor_config sht20_sensor_config;

    // Buffer
    float temperature;
    float humidity;
};

_Bool sht20_read_temperature(struct _sht20*);

_Bool sht20_read_humidity(struct _sht20*);

_Bool sht20_iic_hold_read(uint8_t, uint8_t, uint8_t*, uint16_t, int);

void sht20_init(struct _sht20*, int, int);

#endif