#pragma once

#include "stdint.h"

#define RCVM_HEADER_EXPECTED ((uint64_t)0x5243564D);

typedef struct rcvm_header_t {
    uint32_t header; // {'R','C','V','M'}, rcvm_header_expected
    uint64_t rom_size;
    uint32_t rcvm_compiled_version;
} rcvm_header_t;