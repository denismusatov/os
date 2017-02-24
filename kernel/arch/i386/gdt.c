#include <stdint.h>
#include <stdio.h>

struct gdt_entry
{
    uint16_t limit_low;
    uint16_t base_low;
    uint8_t base_middle;
    uint8_t access;
    uint8_t granularity;
    uint8_t base_high;
} __attribute__((packed));

struct gdt_ptr
{
    uint16_t limit;
    uint32_t base;
} __attribute__((packed));

struct gdt_entry gdt[3];
struct gdt_ptr gdtp;

extern void gdt_flush();

void gdt_set_gate(int32_t num, uint32_t base,
                  uint32_t limit, uint8_t access, uint8_t gran)
{
    gdt[num].base_low = (base & 0xFFFF);
    gdt[num].base_middle = (base >> 16) & 0xFF;
    gdt[num].base_high = (base >> 24) & 0xFF;

    gdt[num].limit_low = (limit & 0xFFFF);
    gdt[num].granularity = ((limit >> 16) & 0x0F);

    gdt[num].granularity |= (gran & 0xF0);
    gdt[num].access = access;
}

void gdt_install()
{
    int32_t pointer = &gdtp;

    printf("Address of this gdt is %i\n", pointer);
    /* Setup the GDT pointer and limit */
    gdtp.limit = (sizeof(struct gdt_entry) * 3) - 1;
    gdtp.base = &gdt;

    /* Our NULL descriptor */
    gdt_set_gate(0, 0, 0, 0, 0);

    /* The second entry is our Code Segment. The base address
     * is 0, the limit is 4GBytes, it uses 4KByte granularity,
     * uses 32-bit opcodes, and is a Code Segment descriptor */
    gdt_set_gate(1, 0, 0xFFFFFFFF, 0x9A, 0xCF);

    /* The third entry is our Data Segment. It's EXACTLY the
     * same as our code segment, but the descriptor type in
     * this entry's access byte says it's a Data Segment */
    gdt_set_gate(2, 0, 0xFFFFFFFF, 0x92, 0xCF);
    gdt_flush();

    int32_t sgdt = 0;
    //struct gdt_ptr* gdtp2 = 0;
    // __asm__ __volatile__("sgdt %0":"=m"(sgdt)::"memory");
    printf("Address of CPU gdt is %i\n", sgdt);
    printf("'gdt_install' completed\n");
}

