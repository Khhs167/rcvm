#include "rcvm_machine.h"
#include "string.h"
#include "stdlib.h"
#include "rcvm_bitconv.h"
#include "rcvm_metadata.h"
#include "rcvm_callbacks.h"

rcvm_machine_t* rcvm_machine_create(rcvm_file_t* file) {

}

void rcvm_machine_destroy(rcvm_machine_t* machine) {
    free(machine->rom);
    free(machine);
}

void rcvm_machine_step(rcvm_machine_t* machine) {

}