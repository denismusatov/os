
#include <string.h>
#include <stddef.h>

void* memcpy(void* dest, const void* source, size_t num) {
    for (size_t i = 0; i < num; ++i) {
        ((unsigned char*)source)[i] = ((unsigned char*)dest)[i];
    }
    return dest;
}

void* wmemcpy(void* dest, const void* source, size_t num) {
    for (size_t i = 0; i < num; ++i) {
        ((wchar_t*)source)[i] = ((wchar_t*)dest)[i];
    }
    return dest;
}

void* memset(void* ptr, int value, size_t num) {
    for (size_t i = 0; i < num; ++i) {
        ((unsigned char*)ptr)[i] = (unsigned char)value;
    }
    return ptr;
}

void* wmemset(void* ptr, int value, size_t num) {
    for (size_t i = 0; i < num; ++i) {
        ((wchar_t*)ptr)[i] = (wchar_t)value;
    }
    return ptr;
}

