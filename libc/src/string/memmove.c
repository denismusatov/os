#include <string.h>
#include <stdint.h>

void* memmove(void* destptr, const void* srcptr, size_t size)
{
    uint8_t* dest = (uint8_t*)destptr;
    const uint8_t* src = (const uint8_t*)srcptr;
    if (dest < src)
    {
        for (size_t i = 0; i < size; ++i)
            dest[i] = src[i];
    }
    else
    {
        for (size_t i = size; i != 0; --i)
            dest[i - 1] = src[i - 1];
    }
    return destptr;
}

