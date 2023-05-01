#include "rcvm_machine.h"
#include "string.h"
#include "stdlib.h"

rcvm_machine_t* rcvm_machine_create(rcvm_rom_reader reader) {
    char header_data[sizeof(rcvm_header_t)];
    for(int i = 0; i < sizeof(rcvm_header_t); i++) header_data[i] = reader(i);
    
    rcvm_machine_t* machine = malloc(sizeof(rcvm_machine_t));
    memcpy(&machine->header, header_data, sizeof(rcvm_header_t));
}

void rcvm_machine_destroy(rcvm_machine_t* machine) {
    free(machine->rom);
    free(machine);
}

void rcvm_machine_step(rcvm_machine_t* machine) {

}