#include <stdio.h>
#include <stdlib.h>

__attribute__((__noreturn__))
void abort()
{
#if defined(__is_klibc)
    printf("kernel: panic: abort()\n");
#else
    printf("abort()\n");
#endif
    for (;;) { }
    __builtin_unreachable();
}

