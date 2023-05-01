#include "stdio.h"
#include "rcvm_machine.h"

void convertToCharArray(unsigned char *arr, uint64_t a)
{
    int i = 0;

    for (i = 0; i < 8; ++i)
    {
        arr[i] = (uint8_t)((((uint64_t) a) >> (56 - (8*i))) & 0xFFu);
    }
}

int main() {
    printf("rcvm - ReCT Virtual Machine\n");

    static uint8_t file[] = {
        // header
        'R', 'C', 'V', 'M', // header.header
        0, 0, 0, 0, 0, 0, 0, 0, // header.rom_size
        0, 0, 0, 0, // header.rcvm_compiled_version
    };

    uint64_t size = sizeof(file);
    convertToCharArray(&file[4], size);

    uint8_t read_file(uint64_t pos) {
        return file[pos];
    }

    rcvm_machine_t* machine = rcvm_machine_create(read_file);

    return 0;
}