#ifndef IO_H
#define IO_H

#include <stdbool.h>
#include <stdint.h>

inline int8_t inb(uint16_t port)
{
    int8_t value;
    __asm__ __volatile__ ("inb %1, %0" : "=a" (value) : "dN" (port));
    return value;
}

inline void outb(uint16_t port, uint8_t data)
{
    __asm__ __volatile__ ("outb %1, %0" : : "dN" (port), "a" (data));
}
#endif

