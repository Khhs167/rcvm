#include "rcvm_machine.h"
#include "string.h"
#include "stdlib.h"
#include "rcvm_bitconv.h"
#include "rcvm_metadata.h"
#include "rcvm_callbacks.h"

rcvm_machine_t* rcvm_machine_create(rcvm_rom_reader reader) {
    char header_data[sizeof(rcvm_header_t)];
    for(int i = 0; i < sizeof(rcvm_header_t); i++) header_data[i] = reader(i);
    
    rcvm_machine_t* machine = malloc(sizeof(rcvm_machine_t));
    memcpy(machine->header.header, header_data, sizeof(uint8_t) * 4);
    machine->header.rom_size = rcvm_frb64(header_data, 0 + 4);
    machine->header.rcvm_compiled_version_major = header_data[0 + 4 + 8];
    machine->header.rcvm_compiled_version_minor = header_data[0 + 4 + 8 + 1];
    machine->header.rcvm_compiled_version_subminor = header_data[0 + 4 + 8 + 2];

    if(machine->header.rcvm_compiled_version_major != RCVM_VERSION_CURRENT_MAJOR) {
        rcvm_throw_error("RCVM Binary compiled for incompatible version of RCVM");
    }
    if(machine->header.rcvm_compiled_version_minor > RCVM_VERSION_CURRENT_MINOR) {
        rcvm_throw_error("RCVM Binary compiled for more recent version of RCVM");
    }
    // Subminor shouldn't matter, as per versioning standards
}

void rcvm_machine_destroy(rcvm_machine_t* machine) {
    free(machine->rom);
    free(machine);
}

void rcvm_machine_step(rcvm_machine_t* machine) {

}