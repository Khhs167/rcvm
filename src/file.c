#include "rcvm_file.h"
#include "rcvm_metadata.h"
#include "rcvm_callbacks.h"
#include "rcvm_bitconv.h"
#include "stdlib.h"

rcvm_file_t* rcvm_file_load(rcvm_rom_reader reader) {
    char header_data[sizeof(rcvm_header_t)];
    for(int i = 0; i < sizeof(rcvm_header_t); i++) header_data[i] = reader(i);
    
    rcvm_file_t* file = malloc(sizeof(rcvm_file_t));
    file->header.header[0] = header_data[0];
    file->header.header[1] = header_data[1];
    file->header.header[2] = header_data[2];
    file->header.header[3] = header_data[3];
    file->header.file_size = rcvm_frb64(header_data, 0 + 4);
    file->header.rcvm_compiled_version_major =      header_data[0 + 4 + 8];
    file->header.rcvm_compiled_version_minor =      header_data[0 + 4 + 8 + 1];
    file->header.rcvm_compiled_version_subminor =   header_data[0 + 4 + 8 + 2];
    file->header.library_offset = rcvm_frb64(header_data, 0 + 4 + 8 + 3);

    if(file->header.rcvm_compiled_version_major != RCVM_VERSION_CURRENT_MAJOR) {
        rcvm_throw_error("RCVM Binary compiled for incompatible version of RCVM");
    }
    if(file->header.rcvm_compiled_version_minor > RCVM_VERSION_CURRENT_MINOR) {
        rcvm_throw_error("RCVM Binary compiled for more recent version of RCVM");
    }
    // Subminor shouldn't matter, as per versioning standards
    
    file->file_data = malloc(file->header.file_size);
    rcvm_log("Loading entire files data(%lu bytes)", file->header.file_size);
    for(uint64_t i = 0; i < file->header.file_size; i++) {
        file->file_data[i] = reader(i);
    }
    rcvm_log("Loaded file data");
    file->rom = file->file_data + sizeof(rcvm_header_t);

    uint8_t* lib = file->file_data + file->header.library_offset;
    file->library_header.name = lib[0];
    file->library_header.symbol_count = rcvm_frb64(lib, 1);

    file->symbols = lib + sizeof(rcvm_library_header_t);
    

    return file;
}

void rcvm_file_destroy(rcvm_file_t* file) {
    free(file->file_data);
    free(file);
}