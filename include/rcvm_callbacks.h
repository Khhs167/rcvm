#pragma once

#include "stdarg.h"

typedef void(*rcvm_error_callback)(const char* message);

void rcvm_throw_error(const char* message);
void rcvm_set_error_callback(rcvm_error_callback callback);

typedef void(*rcvm_log_callback)(const char* message, va_list args);

void rcvm_log(const char* message, ...);
void rcvm_set_log_callback(rcvm_log_callback callback);