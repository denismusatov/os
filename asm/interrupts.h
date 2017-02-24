#ifndef INTERRUPTS_H
#define INTERRUPTS_H

#include <stdbool.h>
#include <stdint.h>


inline bool interrupts_are_enabled()
{
    unsigned long flags;
    __asm__ __volatile__ ("pushf\n\t"
                          "pop %0" : "=g"(flags));
    return flags & (1 << 9);
}

inline void enable_interrupts()
{
    __asm__ ("sti");
}

inline void disable_interrupts()
{
    __asm__ ("cli");
}

inline void halt()
{
    __asm__ ("hlt");
}

inline void iret()
{
    __asm__ ("iret");
}

#endif

