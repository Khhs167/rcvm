#ifndef _RCVM_SYMBOL_H
#define _RCVM_SYMBOL_H

#include "stdint.h"

// A symbol is simply a location, they can be invoked, stored to or whatever you feel like.
// In other words, they're an unresolved integer.
// Symbols need to be manually loaded, however this is not too complex to do.
typedef struct rcvm_symbol_t {
    uint32_t hash;
    uint8_t binary_id;
    uint64_t location;
} rcvm_symbol_t;

typedef struct rcvm_library_header_t {
    uint8_t name;
    uint64_t symbol_count;
} __attribute__((packed)) rcvm_library_header_t;

typedef struct rcvm_library_t {
    rcvm_library_header_t header;
    rcvm_symbol_t* symbols;
} rcvm_library_t;

#endif