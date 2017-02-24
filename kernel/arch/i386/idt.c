#include <sys/system.h>
#include <string.h>
#include <stdio.h>

struct idt_descr
{
    uint16_t limit;
    uint32_t base;
} __attribute__((packed));

struct idt_entry
{
    uint16_t base_lo;
    uint16_t sel;
    uint8_t zero;
    uint8_t flags;
    uint16_t base_hi;
} __attribute__((packed));

struct idt_descr idt_descr;
struct idt_entry idt[256];

extern void setup_idt();

void idt_set_gate(uint8_t num, uint32_t base, uint16_t sel, uint8_t flags)
{
    struct idt_entry* entry = &idt[num];
    entry->base_lo = base & 0x0000FFFF;
    entry->sel = sel;
    entry->zero = 0;
    entry->flags = flags;
    entry->base_hi = base >> 16;
}

void set_system_gate(int n, int* addr)
{

}

void set_trap_gate(int n, int* addr)
{

}

void idt_install()
{
    printf("Setting up IDT\n");
    idt_descr.limit = (sizeof(struct idt_entry) * 256) - 1;
    idt_descr.base = (uint32_t)&idt;
    memset(&idt, 0, sizeof(struct idt_entry)*256);
    setup_idt();
    printf("Dummy IDT has been set\n");
}

