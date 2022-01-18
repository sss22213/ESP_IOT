#ifndef __MESSAGE_H__
#define __MESSAGE_H__
#include "device_info.h"
#include <string.h>
#include <stdint.h>
#include <stdio.h>

struct _message {
    char *name;
    int type;
    float value;
    int timestamp;
    int pid;
    int vid; 
    char *uuid;
};

void message_pack(char*, int, float, int, int, int, char*, char*);
void message_unpack(struct _message*, char*);

#endif