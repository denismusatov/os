#include <string.h>
#include <stddef.h>

void* memcpy(void* dest, const void* source, size_t num) {
    for (size_t i = 0; i < num; ++i) {
        ((unsigned char*)source)[i] = ((unsigned char*)dest)[i];
    }
    return dest;
}

