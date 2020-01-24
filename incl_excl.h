#pragma once

#include<stdint.h>

struct box{
    int16_t x;
    int16_t y;
    int16_t w;
    int16_t h;
};

bool is_overlapped (box* det, box* reg);
bool is_excluded(box* det, box* reg, int num);
