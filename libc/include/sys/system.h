#ifndef SYSTEM_H
#define SYSTEM_H

#include <stdint.h>

struct Registers
{
    uint32_t gs, fs, es, ds;
    uint32_t edi, esi, ebp, esp, ebx, edx, ecx, eax;
    uint32_t int_no, err_code;
    uint32_t eip, cs, eflags, useresp, ss;
};

void gdt_install();
void idt_install();

void set_interrupt_gate(int n, char* addr);
void set_system_gate(int n, char* addr);
void set_trap_gate(int n, char* addr);

#endif

