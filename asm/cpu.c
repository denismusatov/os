#include "cpu.h"

uint32_t get_cr0_value()
{
    uint32_t cr0;
    __asm__ __volatile__ (
            "mov %%cr0, %%eax\n\t"
            "mov %%eax, %0\n\t"
             : "=m" (cr0)
             : /* no input */
             : "%eax");
    return cr0;
}

uint32_t get_cr2_value()
{
    uint32_t cr2;
    __asm__ __volatile__ (
            "mov %%cr2, %%eax\n\t"
            "mov %%eax, %0\n\t"
             : "=m" (cr2)
             : /* no input */
             : "%eax");
    return cr2;
}

uint32_t get_cr3_value()
{
    uint32_t cr3;
    __asm__ __volatile__ (
            "mov %%cr3, %%eax\n\t"
            "mov %%eax, %0\n\t"
             : "=m" (cr3)
             : /* no input */
             : "%eax");
    return cr3;
}

bool protected_mode_is_enabled()
{
    return get_cr0_value() & 0x1;
}

