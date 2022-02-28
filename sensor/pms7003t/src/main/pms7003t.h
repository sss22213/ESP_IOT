#ifndef __PMS7003T__H__
#define __PMS7003T__H__
#include <stdint.h>
#include <stdlib.h>
#include <stdio.h>
#include "freertos/FreeRTOS.h"
#include "freertos/task.h"
#include "driver/uart.h"
#include "driver/gpio.h"

typedef struct pms7003t_data pms7003t_data;
typedef struct pms7003t_data {
    uint8_t uart_num;
    int PM1_0;
    int PM2_5;
    int PM10;
    float temperature;
    float humidity;
} pms7003t_data;

QueueHandle_t uart_queue;
QueueHandle_t pms7003t_queue;

pms7003t_data *pms7003t_initial(uint8_t uart_num);
void pms7003t_read(pms7003t_data*);

#endif