#include "rcvm_bitconv.h"

void rcvm_tob64(uint64_t value, void* target){
    uint8_t* dest = (uint8_t*)target;

    dest[0] = value >> 8*0;
    dest[1] = value >> 8*1;
    dest[2] = value >> 8*2;
    dest[3] = value >> 8*3;
    dest[4] = value >> 8*4;
    dest[5] = value >> 8*5;
    dest[6] = value >> 8*6;
    dest[7] = value >> 8*7;
}

void rcvm_tob32(uint32_t value, void* target){
    uint8_t* dest = (uint8_t*)target;

    dest[0] = value >> 8*0;
    dest[1] = value >> 8*1;
    dest[2] = value >> 8*2;
    dest[3] = value >> 8*3;
}

void rcvm_tob16(uint16_t value, void* target){
    uint8_t* dest = (uint8_t*)target;

    dest[0] = value >> 8*0;
    dest[1] = value >> 8*1;
}

uint64_t rcvm_frb64(void* src, uint32_t offset){
    uint8_t* data = (uint8_t*)src;
    data += offset;

    return ((uint64_t)data[0] << 8 * 0) |
           ((uint64_t)data[1] << 8 * 1) |
           ((uint64_t)data[2] << 8 * 2) |
           ((uint64_t)data[3] << 8 * 3) |
           ((uint64_t)data[4] << 8 * 4) |
           ((uint64_t)data[5] << 8 * 5) |
           ((uint64_t)data[6] << 8 * 6) |
           ((uint64_t)data[7] << 8 * 7);
}

uint32_t rcvm_frb32(void* src, uint32_t offset){
    uint8_t* data = (uint8_t*)src;
    data += offset;

    return ((uint64_t)data[0] << 8 * 0) |
           ((uint64_t)data[1] << 8 * 1) |
           ((uint64_t)data[2] << 8 * 2) |
           ((uint64_t)data[3] << 8 * 3);
}

uint16_t rcvm_frb16(void* src, uint32_t offset){
    uint8_t* data = (uint8_t*)src;
    data += offset;

    return ((uint64_t)data[0] << 8 * 0) |
           ((uint64_t)data[1] << 8 * 1);
}
