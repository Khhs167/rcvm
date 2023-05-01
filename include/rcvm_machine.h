#pragma once

#include "rcvm_header.h"
#include "stdint.h"

typedef enum rcvm_registers_e {
    REG_GWX = 0,
    REG_GWY = 1,
    REG_GWZ = 2,

    REG_GDX = 3,
    REG_GDY = 4,
    REG_GDZ = 5,

    REG_SB = 6,
    REG_ST = 7,
} rcvm_registers_e;

typedef uint8_t (*rcvm_rom_reader)(uint64_t);

typedef struct rcvm_machine_t
{
    rcvm_header_t header;
    uint8_t* rom;
    
    // One word => 32 bits
    // One dword => 64 bits
    uint32_t gwx; // General Word (Register) X
    uint32_t gwy; // General Word (Register) Y
    uint32_t gwz; // General Word (Register) Z

    uint64_t gdx; // General Double(Word) (Register) X
    uint64_t gdy; // General Double(Word) (Register) Y
    uint64_t gdz; // General Double(Word) (Register) Z

    uint32_t sb; // Stack base
    uint32_t st; // Stack top
} rcvm_machine_t;

rcvm_machine_t* rcvm_machine_create(rcvm_rom_reader reader);
void rcvm_machine_destroy(rcvm_machine_t* machine);
void rcvm_machine_step(rcvm_machine_t* machine);