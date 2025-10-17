#include "error.h"
#include <stdlib.h>

static ErrorInfo current_error = {ERR_NONE, NULL, NULL, 0};

void error_init(void) {
    current_error.code = ERR_NONE;
    current_error.message = NULL;
    current_error.file = NULL;
    current_error.line = 0;
}

void error_set(ErrorCode code, const char* message, const char* file, int line) {
    current_error.code = code;
    current_error.message = message;
    current_error.file = file;
    current_error.line = line;
}

ErrorInfo* error_get(void) {
    return &current_error;
}

void error_clear(void) {
    current_error.code = ERR_NONE;
    current_error.message = NULL;
    current_error.file = NULL;
    current_error.line = 0;
}