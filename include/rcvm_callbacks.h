#pragma once

typedef void(*rcvm_error_callback)(const char* message);

void rcvm_throw_error(const char* message);
void rcvm_set_error_callback(rcvm_error_callback callback);