#ifndef _RCVM_MACHINE_H
#define _RCVM_MACHINE_H

#include "stdint.h"

#include "rcvm_header.h"
#include "rcvm_symbol.h"
#include "rcvm_file.h"

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


typedef struct rcvm_machine_core_t
{
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

    uint64_t pr; // Program pointer

    uint8_t lp; // Library pointer, used to store the current working library

    uint8_t enabled; // Is the core enabled(does it execute instructions?)
} rcvm_machine_core_t;
typedef struct rcvm_machine_t
{
    rcvm_header_t header;
    uint8_t* rom;

    // By default each machine has 16 cores, for a total of 16 threads
    rcvm_machine_core_t cores[16];
    // 256 library descriptors isn't really a lot
    rcvm_library_t libraries[256];
    
} rcvm_machine_t;


rcvm_machine_t* rcvm_machine_create(rcvm_file_t* reader);
void rcvm_machine_destroy(rcvm_machine_t* machine);
void rcvm_machine_step(rcvm_machine_t* machine);

#endif