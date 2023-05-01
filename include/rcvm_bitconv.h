#pragma once

#include "stdint.h"

void rcvm_tob64(uint64_t value, void* target);
void rcvm_tob32(uint32_t value, void* target);
void rcvm_tob16(uint16_t value, void* target);

uint64_t rcvm_frb64(void* src, uint32_t offset);
uint32_t rcvm_frb32(void* src, uint32_t offset);
uint16_t rcvm_frb16(void* src, uint32_t offset);