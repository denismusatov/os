#include <stddef.h>
#include "../include/string.h"

extern void terminal_write(const char* data, size_t size);

int printf(const char* data) {
    const size_t length = strlen(data);
    terminal_write(data, length);
    return (int)length;
}

