#include <libc.h>
#include <stdint.h>
#include <stdlib.h>
#include <stdio.h>

#if UINT32_MAX == UINTPTR_MAX
#define STACK_CHK_GUARD 0xEEF415A2
#else
#define STACK_CHK_GUARD 0x2F76190BEF7F4432
#endif

uintptr_t __stack_chk_guard = STACK_CHK_GUARD;

__attribute__((noreturn))
void __stack_chk_fail()
{
#if __STDC_HOSTED__
    abort();
#else
    printf("\nStack smashing detected\n");
    abort();
    // panic("\nStack smashing detected\n");
#endif
    for (;;) {}
}

