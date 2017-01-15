#include "interrupts.h"


bool interrupts_are_enabled()
{
    unsigned long flags;
    __asm__ __volatile__ ("pushf\n\t"
                          "pop %0" : "=g"(flags));
    return flags & (1 << 9);
}

void enable_interrupts()
{
    __asm__ ("sti");
}

void disable_interrupts()
{
    __asm__ ("cli");
}

