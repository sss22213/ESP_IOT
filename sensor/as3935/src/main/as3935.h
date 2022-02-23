#ifndef __AS3935_H__
#define __AS3935_H__
#include <stdint.h>
#include <stdbool.h>
#include "as3935_hal.h"

#define INIT_AS3935_DEVICE(AS3935_NAME) \
                            struct _as3935_device (AS3935_NAME); \
                            as3935_spi_initial(); \
                            as3935_set_power(&AS3935_NAME, AS3935_POWER_ON);

typedef enum {
    _AS3935_SPI_MODE_WRITE_DIRECT = 0,
    _AS3935_SPI_MODE_READ
} _AS3935_SPI_MODE;

typedef enum {
    AS3935_NOISE_FLOOR_THRESHOLD_NOISE_LEVEL_390_28 = 0,
    AS3935_NOISE_FLOOR_THRESHOLD_NOISE_LEVEL_630_45,
    AS3935_NOISE_FLOOR_THRESHOLD_NOISE_LEVEL_860_62,
    AS3935_NOISE_FLOOR_THRESHOLD_NOISE_LEVEL_1100_78,
    AS3935_NOISE_FLOOR_THRESHOLD_NOISE_LEVEL_1140_95,
    AS3935_NOISE_FLOOR_THRESHOLD_NOISE_LEVEL_1570_112,
    AS3935_NOISE_FLOOR_THRESHOLD_NOISE_LEVEL_1800_130,
    AS3935_NOISE_FLOOR_THRESHOLD_NOISE_LEVEL_2000_146
} AS3935_NOISE_FLOOR_THRESHOLD;

typedef enum {
    AS3935_INTERRUPT_EVENT_NOISE_LEVEL_TO_HIGH = 0x01,
    AS3935_INTERRUPT_EVENT_DISTURBER_DETECTED = 0x04,
    AS3935_INTERRUPT_EVENT_LIGHTNING_INTERRUP = 0x08
} AS3935_INTERRUPT_EVENT;

typedef enum {
    AS3935_POWER_DOWN = 0,
    AS3935_POWER_ON
} AS3935_POWER;

struct _as3935_reg_table {
    union {
        // 0x00~0x08, 0x3A, 0x3B
        uint8_t reg_val[11];
        struct {
            union {
                uint8_t loc_3B;
                struct { 
                    uint8_t SRCO_CALIB_DONE : 1;
                    uint8_t SRCO_CALIB_NOK : 1;
                    uint8_t RESERVED : 6;
                } as3935_reg_table_loc_3B;
            };
            union {
                uint8_t loc_3A;
                struct { 
                    uint8_t TRCO_CALIB_DONE : 1;
                    uint8_t TRCO_CALIB_NOK : 1;
                    uint8_t RESERVED : 6;
                } as3935_reg_table_loc_3A;
            };
            union {
                uint8_t loc_8;
                struct { 
                    uint8_t DISP_LCO : 1;
                    uint8_t DISP_SROC : 1;
                    uint8_t DISP_TROC : 1;
                    uint8_t RESERVED : 1;
                    uint8_t TUN_CAP : 4;
                } as3935_reg_table_loc_8;
            };
            union {
                uint8_t loc_7;
                struct { 
                    uint8_t RESERVED : 2;
                    uint8_t DISTANCE : 6;
                } as3935_reg_table_loc_7;
            };
            union {
                uint8_t loc_6;
                struct { 
                    uint8_t RESERVED : 2;
                    uint8_t S_LIG_MM : 6;
                } as3935_reg_table_loc_6;
            };
            union {
                uint8_t loc_5;
                struct { 
                    uint8_t S_LIG_M;
                } as3935_reg_table_loc_5;
            };
            union {
                uint8_t loc_4;
                struct { 
                    uint8_t S_LIG_L;
                } as3935_reg_table_loc_4;
            };
            union {
                uint8_t loc_3;
                struct { 
                    uint8_t LCO_FDIV : 2;
                    uint8_t MASK_DIST : 1;
                    uint8_t RESERVED : 1;
                    uint8_t INT : 4;
                } as3935_reg_table_loc_3;
            };
            union {
                uint8_t loc_2;
                struct { 
                    uint8_t RESERVED : 1;
                    uint8_t CL_STAT : 1;
                    uint8_t MIN_NUM_LIGH : 2;
                    uint8_t SREJ : 4;
                } as3935_reg_table_loc_2;
            };
            union {
                uint8_t loc_1;
                struct { 
                    uint8_t RESERVED : 1;
                    uint8_t NF_LEV : 3;
                    uint8_t WDTH : 4;
                } as3935_reg_table_loc_1;
            };
            union {
                uint8_t loc_0;
                struct { 
                    uint8_t RESERVED : 2;
                    uint8_t AFE_GB : 5;
                    uint8_t PWD : 1;
                } as3935_reg_table_loc_0;
            };
        } as3935_reg_table_byte;
    };
};

struct _as3935_device {
    struct _as3935_reg_table as3935_reg;
    /*
    union {
        uint16_t package_val;
        struct {
            uint8_t reg_val : 8;
            uint8_t reg_addr : 6;
            uint8_t mode : 2;
        } as3935_communcation_byte;
    };
    */
};

_Bool as3935_set_power(struct _as3935_device*, AS3935_POWER);

int32_t as3935_get_lightning_distance(struct _as3935_device*);

#endif