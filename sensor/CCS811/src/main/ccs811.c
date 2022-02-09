#include "ccs811.h"

#define ERROR_CHECK() _error_flag(ccs811_device)

static inline _Bool _error_flag(struct _ccs811_device *ccs811_device)
{
    ccs811_iic_mem_read_byte(_CCS811_REG_ADDRESS_STATUS, &(ccs811_device->ccs811_reg_status.reg_val), 1);

    return ((ccs811_device->ccs811_reg_status._ccs811_status_bytes.error)?true:false);
}

static inline _Bool _read_alg_result_data(struct _ccs811_device *ccs811_device)
{
    ccs811_iic_mem_read_byte(_CCS811_REG_ADDRESS_ALG_RESULT_DATA, ccs811_device->ccs811_reg_alg_result_data.reg_val, 8);

    return ERROR_CHECK();
}

void ccs811_init(struct _ccs811_device *ccs811_device, \
                int scl_pin, int sda_pin, \
                _CCS811_MODE_CONFIG ccs811_mode_config, \
                _CCS811_MODE_INT_DATARDY ccs811_mode_int_datardy, \
                _CCS811_MODE_INT_THRESH ccs811_mode_int_thresh)
{
    _Bool res = false;

    ccs811_iic_initial(scl_pin, sda_pin);

    ccs811_device->ccs811_reg_meas_mode._ccs811_meas_mode_bytes.drive_mode = ccs811_mode_config;
    ccs811_device->ccs811_reg_meas_mode._ccs811_meas_mode_bytes.int_datardy = ccs811_mode_int_datardy;
    ccs811_device->ccs811_reg_meas_mode._ccs811_meas_mode_bytes.int_thresh = ccs811_mode_int_thresh;

    res = ccs811_iic_mem_write_byte(_CCS811_REG_ADDRESS_MEAS_MODE, &(ccs811_device->ccs811_reg_meas_mode.reg_val), 1);
}

_Bool ccs811_read_eco2(struct _ccs811_device *ccs811_device, uint16_t *eco2_val)
{
    _Bool res = _read_alg_result_data(ccs811_device);

    *eco2_val = (ccs811_device->ccs811_reg_alg_result_data._ccs811_alg_result_bytes.eco2_MSB << 8) |\
                (ccs811_device->ccs811_reg_alg_result_data._ccs811_alg_result_bytes.eco2_LSB);

    return res;
}

_Bool ccs811_read_tvoc(struct _ccs811_device *ccs811_device, uint16_t *tvoc_val)
{
    _Bool res = _read_alg_result_data(ccs811_device);

    *tvoc_val = (ccs811_device->ccs811_reg_alg_result_data._ccs811_alg_result_bytes.tvoc_MSB << 8) |\
                (ccs811_device->ccs811_reg_alg_result_data._ccs811_alg_result_bytes.tvoc_LSB);

    return res;
}