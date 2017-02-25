#include <sys/system.h>
#include <string.h>
#include <stdio.h>

struct IdtEntry
{
    uint16_t offset_low;
    uint16_t selector;
    uint8_t zero;
    uint8_t type_attr;
    uint16_t offset_hi;
} __attribute__((packed));

struct IdtInfo
{
    uint16_t size;
    uint32_t offset;
} __attribute__((packed));

struct IdtInfo idt_info;
struct IdtEntry idt[256];

extern void setup_idt();

static void idt_set_gate(uint8_t num, uint32_t base,
                         uint16_t sel, uint8_t flags)
{
    struct IdtEntry* entry = &idt[num];
    entry->offset_low = base & 0x0000FFFF;
    entry->selector = sel;
    entry->zero = 0;
    entry->type_attr = flags;
    entry->offset_hi = base >> 16;
}

void set_interrupt_gate(int n, char* addr)
{
    idt_set_gate(n, 0, addr, 14);
}

void set_system_gate(int n, char* addr)
{
    idt_set_gate(n, 3, addr, 15);
}

void set_trap_gate(int n, char* addr)
{
    idt_set_gate(n, 0, addr, 15);
}

void idt_install()
{
    printf("Setting up IDT\n");
    idt_info.size = (sizeof(struct IdtEntry) * 256) - 1;
    idt_info.offset = (uint32_t)&idt;
    memset(&idt, 0, sizeof(struct IdtEntry)*256);
    setup_idt();
    printf("Dummy IDT has been set\n");
}

