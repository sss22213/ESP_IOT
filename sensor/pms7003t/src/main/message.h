#ifndef __MESSAGE_H__
#define __MESSAGE_H__
#include "device_info.h"
#include <string.h>
#include <stdint.h>
#include <stdio.h>

#define MESSAGE_NAME_MAXIMUN_SIZE   200
#define MESSAGE_UUID_MAXIMUN_SIZE   1024

struct _message {
    char name[MESSAGE_NAME_MAXIMUN_SIZE];
    int type;
    float value;
    float arg0;
    int timestamp;
    int pid;
    int vid; 
    char uuid[MESSAGE_UUID_MAXIMUN_SIZE];
};

void message_pack(char*, int, float, float, int, int, int, char*, char*);
void message_unpack(struct _message*, char*);

#endif