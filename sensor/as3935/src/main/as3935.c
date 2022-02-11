#include "as3935.h"

static inline _Bool _read_reg(struct _as3935_device *as3935_device, uint8_t reg_address)
{
    uint8_t buf = 0x00;

    if (reg_address < 0x09 || reg_address == 0x3A || reg_address == 0x3B) {
        as3935_read_reg(reg_address, &buf, 1);
    } else {
        return false;
    }

    as3935_device->as3935_reg.reg_val[reg_address] = buf;

    return true;
}

static inline _Bool _write_reg(struct _as3935_device *as3935_device, uint8_t reg_address)
{
    uint8_t write_buffer = 0;

    struct _as3935_device as3935_device_reg;

    _read_reg(&as3935_device_reg, reg_address);

    if (reg_address < 0x09) {
        write_buffer = as3935_device->as3935_reg.reg_val[reg_address] | as3935_device_reg.as3935_reg.reg_val[reg_address];
    } else if (reg_address == 0x3A || reg_address == 0x3B) {
        write_buffer = as3935_device->as3935_reg.reg_val[(reg_address-0x3A)+9] | as3935_device_reg.as3935_reg.reg_val[(reg_address-0x3A)+9];
    } else {
        return false;
    }
    
    as3935_write_reg(reg_address, write_buffer, 1);
    
    /*
    if (reg_address < 0x09) {
        as3935_write_reg(reg_address, as3935_device->as3935_reg.reg_val[reg_address], 1);
    } else if (reg_address == 0x3A || reg_address == 0x3B) {
        as3935_write_reg(reg_address, as3935_device->as3935_reg.reg_val[(reg_address-0x3A)+9], 1);
    } else {
        return false;
    }
    */

    return true;
}

// Noise Floor Threshold
static inline _Bool _set_noise_floor_threshold(struct _as3935_device *as3935_device, \
                                                AS3935_NOISE_FLOOR_THRESHOLD as3935_noise_floor_threshold)
{
    as3935_device->as3935_reg.as3935_reg_table_byte.as3935_reg_table_loc_1.NF_LEV = as3935_noise_floor_threshold;

    _write_reg(as3935_device, 0x01);

    return true;
}

// MINIMUM_NUMBER_OF_LIGHTNING
static inline _Bool _set_minimum_number_of_lightning(struct _as3935_device *as3935_device, uint8_t number_of_lightning)
{
    as3935_device->as3935_reg.as3935_reg_table_byte.as3935_reg_table_loc_2.MIN_NUM_LIGH = number_of_lightning;

    _write_reg(as3935_device, 0x01);

    return true;
}

// Spike rejection
static inline _Bool _set_spike_rejection(struct _as3935_device *as3935_device, uint8_t spike_rejection_val)
{
    as3935_device->as3935_reg.as3935_reg_table_byte.as3935_reg_table_loc_2.SREJ = spike_rejection_val;

    //_write_reg(as3935_device, 0x02);
    
    return true;
}

// 
static inline AS3935_INTERRUPT_EVENT _get_interrupt_event(struct _as3935_device *as3935_device)
{
    _read_reg(as3935_device, 0x03);

    return as3935_device->as3935_reg.as3935_reg_table_byte.as3935_reg_table_loc_3.INT;
}

/*
static inline _Bool _clear_lightning_statistics(struct _as3935_device *as3935_device)
{
    as3935_device->as3935_reg.as3935_reg_table_loc_2.CL_STAT = 1;

    _write_reg(as3935_device, 0x02);

    return true;
}
*/

// Lightning distance
int32_t as3935_get_lightning_distance(struct _as3935_device *as3935_device)
{
    _read_reg(as3935_device, 0x07);

    if (as3935_device->as3935_reg.as3935_reg_table_byte.as3935_reg_table_loc_7.DISTANCE <= 40) {
        return as3935_device->as3935_reg.as3935_reg_table_byte.as3935_reg_table_loc_7.DISTANCE;
    } else {
        return -1;
    }
}


_Bool as3935_set_power(struct _as3935_device *as3935_device, AS3935_POWER as3935_power_status)
{
    as3935_device->as3935_reg.as3935_reg_table_byte.as3935_reg_table_loc_0.PWD = as3935_power_status;

    _write_reg(as3935_device, 0x00);

    return true;
}

