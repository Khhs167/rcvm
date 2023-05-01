#pragma once

#include "stdint.h"

// A symbol is simply a location, they can be invoked, stored to or whatever you feel like.
// In other words, they're an unresolved integer.
// Symbols need to be manually loaded, however this is not too complex to do.
typedef struct rcvm_symbol_t {
    uint32_t hash;
    uint8_t binary_id;
    uint64_t location;
};