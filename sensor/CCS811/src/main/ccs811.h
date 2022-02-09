#ifndef __CCS811_H__
#define __CCS811_H__
#include <stdint.h>
#include "ccs811_hal.h"

#define INIT_CCS811(CCS811_NAME, SCL_PIN, SDA_PIN) \
                    struct _ccs811_device (CCS811_NAME); \
                    ccs811_init(&CCS811_NAME, SCL_PIN, SDA_PIN, \
                                _CCS811_REG_MODE_1, _CCS811_MODE_INT_DATARDY_DISABLE, \
                                _CCS811_MODE_INT_THRESH_DISABLE);

#define CCS811_HW_ID 0x81
#define CCS811_HW_VERSION(X) ((X) & 0x0F)
#define CCS811_RESET_CMD {0x11, 0xE5, 0x72, 0x8A}

typedef enum {
    _CCS811_REG_ADDRESS_STATUS = 0x00,
    _CCS811_REG_ADDRESS_MEAS_MODE = 0x01,
    _CCS811_REG_ADDRESS_ALG_RESULT_DATA = 0x02,
    _CCS811_REG_ADDRESS_RAW_DATA = 0x03,
    _CCS811_REG_ADDRESS_ENV_DATA = 0x05,
    _CCS811_REG_ADDRESS_NTC = 0x06,
    _CCS811_REG_ADDRESS_THRESHOLDS = 0x10,
    _CCS811_REG_ADDRESS_BASELINE = 0x11,
    _CCS811_REG_ADDRESS_HW_ID = 0x20,
    _CCS811_REG_ADDRESS_HW_Version = 0x21,
    _CCS811_REG_ADDRESS_FW_Boot_Version = 0x23,
    _CCS811_REG_ADDRESS_FW_App_Version = 0x24,
    _CCS811_REG_ADDRESS_ERROR_ID = 0xE0,
    _CCS811_REG_ADDRESS_SW_RESET = 0xEF,
} _CCS811_REG_ADDRESS;

typedef enum {
    _CCS811_REG_MODE_0 = 0,
    _CCS811_REG_MODE_1,
    _CCS811_REG_MODE_2,
    _CCS811_REG_MODE_3,
    _CCS811_REG_MODE_4
} _CCS811_MODE_CONFIG;

typedef enum {
    _CCS811_MODE_INT_DATARDY_DISABLE = 0,
    _CCS811_MODE_INT_DATARDY_ENABLE
} _CCS811_MODE_INT_DATARDY;

typedef enum {
    _CCS811_MODE_INT_THRESH_DISABLE = 0,
    _CCS811_MODE_INT_THRESH_ENABLE
} _CCS811_MODE_INT_THRESH;

struct _ccs811_reg_status {
    union {
        uint8_t reg_val;
        struct {
            uint8_t error : 1;
            uint8_t reserved1 : 2;
            uint8_t data_ready : 1;
            uint8_t app_vaild : 1;
            uint8_t reserved2 : 2;
            uint8_t fw_mode : 1;
        }  _ccs811_status_bytes;
    };
};

struct _ccs811_reg_meas_mode {
    union {
        uint8_t reg_val;
        struct {
            uint8_t reserved1 : 2;
            uint8_t int_thresh : 2;
            uint8_t int_datardy : 1;
            uint8_t drive_mode : 2;
            uint8_t reserved2 : 1;
        } _ccs811_meas_mode_bytes;
    };
};

struct _ccs811_reg_result_data {
    union {
        uint8_t reg_val;
        struct {
            uint8_t reserved1 : 2;
            uint8_t int_thresh : 2;
            uint8_t int_datardy : 1;
            uint8_t drive_mode : 2;
            uint8_t reserved2 : 1;
        } _ccs811_result_data_bytes;
    };
};

struct _ccs811_reg_alg_result_data {
    union {
        uint8_t reg_val[8];
        struct {
            uint8_t eco2_MSB;
            uint8_t eco2_LSB;
            uint8_t tvoc_MSB;
            uint8_t tvoc_LSB;
            uint8_t status;
            uint8_t err_id;
            uint16_t raw_data;
        } _ccs811_alg_result_bytes;
    };
};

struct _ccs811_reg_env_data {
    uint16_t humidity;
    uint16_t temperature;
};

struct _ccs811_reg_fw_boot_version {
    union {
        uint16_t reg_val;
        struct {
            uint8_t minor : 4;
            uint8_t major : 4;
            uint8_t trivial : 8;
        } _ccs811_fw_boot_version_bytes;
    };
};

struct _ccs811_reg_fw_app_version {
    union {
        uint16_t reg_val;
        struct {
            uint8_t minor : 4;
            uint8_t major : 4;
            uint8_t trivial : 8;
        } _ccs811_fw_app_version_bytes;
    };
};

struct _ccs811_reg_err_id {
    union {
        uint8_t reg_val;
        struct {
            uint8_t write_reg_invaild : 1;
            uint8_t read_reg_invaild : 1;
            uint8_t measmode_invaild : 1;
            uint8_t max_resistance : 1;
            uint8_t heater_fault : 1;
            uint8_t heater_supply : 1;
            uint8_t reserved1 : 1;
            uint8_t reserved2 : 1;
        } _ccs811_reg_err_id_bytes;
    };
};

struct _ccs811_device {
    struct _ccs811_reg_status ccs811_reg_status;
    struct _ccs811_reg_meas_mode ccs811_reg_meas_mode;
    struct _ccs811_reg_result_data ccs811_reg_result_data;
    struct _ccs811_reg_alg_result_data ccs811_reg_alg_result_data;
    struct _ccs811_reg_env_data ccs811_reg_env_data;
    struct _ccs811_reg_fw_boot_version ccs811_reg_fw_boot_version;
    struct _ccs811_reg_fw_app_version ccs811_reg_fw_app_version;
    struct _ccs811_reg_err_id ccs811_reg_err_id;
    uint8_t ccs811_hw_version;
};

void ccs811_init(struct _ccs811_device*, int, int, _CCS811_MODE_CONFIG, \
                    _CCS811_MODE_INT_DATARDY, _CCS811_MODE_INT_THRESH);

_Bool ccs811_read_eco2(struct _ccs811_device*, uint16_t*);
_Bool ccs811_read_tvoc(struct _ccs811_device*, uint16_t*);

#endif