#pragma once

#include "stdint.h"

typedef struct rcvm_header_t {
    uint8_t header[4]; // {'R','C','V','M'}
    uint64_t rom_size;
    uint8_t rcvm_compiled_version_major;
    uint8_t rcvm_compiled_version_minor;
    uint8_t rcvm_compiled_version_subminor;
} rcvm_header_t;