#include "stdio.h"
#include "rcvm_machine.h"
#include "rcvm_bitconv.h"

int main() {
    printf("rcvm - ReCT Virtual Machine\n");

    static uint8_t file[] = {
        // header
        'R', 'C', 'V', 'M', // header.header
        0, 0, 0, 0, 0, 0, 0, 0, // header.rom_size
        0, 0, 0, // header.rcvm_compiled_version_(major/minor/subminor)
    };

    uint64_t size = sizeof(file);
    rcvm_tob64(size, file + sizeof(uint8_t) * 4);

    uint8_t read_file(uint64_t pos) {
        return file[pos];
    }

    rcvm_machine_t* machine = rcvm_machine_create(read_file);

    return 0;
}