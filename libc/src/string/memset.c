#include <string.h>
#include <stdint.h>

void* memset(void* ptr, int value, size_t num)
{
    for (size_t i = 0; i < num; ++i) {
        ((unsigned char*)ptr)[i] = (unsigned char)value;
    }
    return ptr;
}

void* wmemset(void* ptr, int value, size_t num)
{
    for (size_t i = 0; i < num; ++i) {
        ((wchar_t*)ptr)[i] = (wchar_t)value;
    }
    return ptr;
}

