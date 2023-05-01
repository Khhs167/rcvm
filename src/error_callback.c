#include "rcvm_callbacks.h"
#include "stdlib.h"
#include "stdio.h"

static rcvm_error_callback _rcvm_error_callback_current = NULL;

void rcvm_throw_error(const char* message) {
    if(_rcvm_error_callback_current == NULL) {
        printf("RCVM ERROR: %s\n", message);
        exit(1);
    }
    _rcvm_error_callback_current(message);
}

void rcvm_set_error_callback(rcvm_error_callback callback) {
    _rcvm_error_callback_current = callback;
}