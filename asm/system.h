#ifndef SYSTEM_H
#define SYSTEM_H

#include <stdint.h>

inline void SetGate(void* gate_address, uint16_t type,
        uint16_t dpl, void* addr)
{
    __asm__ (
            "movw %%dx,%%ax\n\t" \
            "movw %0, %%dx\n\t" \
            "movl %%eax,%1\n\t" \
            "movl %%edx,%2\n\t" \
            :: \
            "i" ((uint16_t)(0x8000+(dpl << 13)+(type << 8))), \
            "o" (*((uint8_t *)gate_address)), \
            "o" (*(4 + (uint8_t *)gate_address)), \
            "d" ((uint8_t*)addr), \
            "a" (0x00080000))
}

inline void SetTrapGate(void* idt, int n, void* address)
{
    SetGate(&idt[n], 15, 0, address);
}

#endif

