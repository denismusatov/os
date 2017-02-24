#ifndef SYSTEM_H
#define SYSTEM_H

#include <stdint.h>

void gdt_install();

void idt_install();
void idt_set_gate(uint8_t num, uint32_t base, uint16_t sel, uint8_t flags);

#endif

