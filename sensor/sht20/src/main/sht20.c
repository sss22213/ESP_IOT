#include "sht20.h"

void sht20_init(struct _sht20 *sht20, int scl_pin, int sda_pin)
{
    sht20_iic_initial(scl_pin, sda_pin);

    memset(sht20, 0, sizeof(struct _sht20));
}

_Bool sht20_read_temperature(struct _sht20 *sht20)
{
    uint8_t temperature_raw[3] = {0};

    uint16_t temperature_sensor_raw = 0;
   
    sht20_iic_hold_read(SHT20_SLAVE_ADDRESS, SHT20_TRIGER_TEMPERATURE_MEASURE_NO_HOLD_COMMAND, temperature_raw, 3, 40);

    temperature_sensor_raw = (uint16_t)temperature_raw[0] << 8 | ((uint16_t)temperature_raw[1] & 0xFC);

    sht20->temperature = -46.85 +  (temperature_sensor_raw/ 65536.0) * 175.72;
    
    return true;
}

_Bool sht20_read_humidity(struct _sht20 *sht20)
{
    uint8_t humidity_raw[3] = {0};

    uint16_t humidity_sensor_raw = 0;
   
    sht20_iic_hold_read(SHT20_SLAVE_ADDRESS, SHT20_TRIGER_HUMIDITY_MEASURE_NO_HOLD_COMMAND, humidity_raw, 3, 20);

    humidity_sensor_raw = (uint16_t)humidity_raw[0] << 8 | ((uint16_t)humidity_raw[1] & 0xFC);

    sht20->humidity = -6.0 +  (humidity_sensor_raw / 65536.0) * 125.0;

    printf("%e\n", sht20->humidity);
    
    return true;
}



static inline void _config(struct _sht20 *sht20)
{
    uint8_t set_value = sht20->sht20_sensor_config.sht20_on_chip_heater_config << SHT20_ON_CHIP_HEATER_BIT |\
                        sht20->sht20_sensor_config.sht20_otp_reload_config << SHT20_OTP_RELOAD_BIT |\
                        sht20->sht20_sensor_config.sht20_status_config << SHT20_STATUS_BIT |\
                        (sht20->sht20_sensor_config.sht20_resolution_config & 0x02) << 6 |\
                        (sht20->sht20_sensor_config.sht20_resolution_config & 0x01);

    
    sht20_iic_mem_write_byte(SHT20_SLAVE_ADDRESS, SHT20_USER_REGISTER, &set_value, 1);

}

void sht20_config(struct _sht20 *sht20, _SHT20_RESOLUTION_CONFIG sht20_resolution_config, _SHT20_STATUS_CONFIG sht20_status_config,  \
                    _SHT20_ON_CHIP_HEATER_CONFIG sht20_on_chip_heater_config, _SHT20_OTP_RELOAD_CONFIG sht20_otp_reload_config)
{
    struct _sht20_sensor_config sht20_sensor_config = {.sht20_resolution_config = sht20_resolution_config,
                                                        .sht20_status_config = sht20_status_config,
                                                        .sht20_on_chip_heater_config = sht20_on_chip_heater_config,
                                                        .sht20_otp_reload_config = sht20_otp_reload_config};

    memcpy(&(sht20->sht20_sensor_config), &sht20_sensor_config, sizeof(struct _sht20_sensor_config));

    _config(sht20);
}
