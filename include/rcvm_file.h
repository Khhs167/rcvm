#ifndef _RCVM_FILE_H
#define _RCVM_FILE_H

#include "rcvm_header.h"
#include "rcvm_symbol.h"


typedef uint8_t (*rcvm_rom_reader)(uint64_t);

typedef struct rcvm_file_t
{
    uint8_t* file_data;
    rcvm_header_t header;
    uint8_t* rom;
    rcvm_library_header_t library_header;
    rcvm_symbol_t* symbols;
} rcvm_file_t;

rcvm_file_t* rcvm_file_load(rcvm_rom_reader reader);
void rcvm_file_destroy(rcvm_file_t* file);

#endif