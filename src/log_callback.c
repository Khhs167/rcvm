#include "rcvm_callbacks.h"
#include "stdlib.h"
#include "stdio.h"

static rcvm_log_callback _rcvm_log_callback_current = NULL;

void rcvm_log(const char* message, ...) {

    va_list args;
    va_start(args, message);

    if(_rcvm_log_callback_current == NULL) {
        printf("RCVM LOG: ");
        vprintf(message, args);
        printf("\n");
    } else {
        _rcvm_log_callback_current(message, args);
    }

    va_end(args);
}

void rcvm_set_log_callback(rcvm_log_callback callback) {
    _rcvm_log_callback_current = callback;
}