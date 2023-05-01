#ifndef _RCVM_HEADER_H
#define _RCVM_HEADER_H

#include "stdint.h"

typedef struct rcvm_header_t {
    uint8_t header[4]; // {'R','C','V','M'}
    uint64_t file_size;
    uint8_t rcvm_compiled_version_major;
    uint8_t rcvm_compiled_version_minor;
    uint8_t rcvm_compiled_version_subminor;
    uint64_t library_offset;
} __attribute__((packed)) rcvm_header_t; // Anything stored in-file should be packed

#endif