#include "stdio.h"
#include "rcvm_machine.h"
#include "rcvm_bitconv.h"
#include "rcvm_file.h"

int main() {

    printf("rcvm - ReCT Virtual Machine\n");

    static rcvm_header_t header;
    static uint8_t file_rom[] = {

    };
    static rcvm_library_header_t library_header;
    static rcvm_symbol_t library[] = {
    };
    header.header[0] = 'R';
    header.header[1] = 'C';
    header.header[2] = 'V';
    header.header[3] = 'M';
    header.file_size = sizeof(header) + sizeof(file_rom) + sizeof(library_header) + sizeof(library);
    header.library_offset = sizeof(header) + sizeof(file_rom);
    header.rcvm_compiled_version_major = 0;
    header.rcvm_compiled_version_minor = 0;
    header.rcvm_compiled_version_subminor = 0;

    library_header.name = 0;
    library_header.symbol_count = sizeof(library) / sizeof(library[0]);


    uint8_t read_file(uint64_t pos) {
        if(pos < sizeof(header))
            return ((uint8_t*)&header)[pos];
        if(pos < header.library_offset) 
            return file_rom[pos - sizeof(header)];
        if(pos < header.library_offset + sizeof(library_header))
            return ((uint8_t*)&library_header)[pos - header.library_offset];

        return ((uint8_t*)&library)[pos - (header.library_offset  + sizeof(library_header))];
    }

    rcvm_file_t* rcvm_file = rcvm_file_load(read_file);

    return 0;
}