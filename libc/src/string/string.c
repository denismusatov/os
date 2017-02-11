#include <string.h>
#include <stddef.h>


void* wmemcpy(void* dest, const void* source, size_t num)
{
    for (size_t i = 0; i < num; ++i) {
        ((wchar_t*)source)[i] = ((wchar_t*)dest)[i];
    }
    return dest;
}

