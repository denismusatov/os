#include "interrupts.h"

#include <stdint.h>


struct IDTDescr {
    uint16_t offset_1; // offset bits 0..15
    uint16_t selector; // a code segment selector in GDT or LDT
    uint8_t zero;      // unused, set to 0
    uint8_t type_attr; // type and attributes, see below
    uint16_t offset_2; // offset bits 16..31
} __attribute__((packed));

//  type_attr is specified here:
//  7                           0
//  +---+---+---+---+---+---+---+---+
//  | P |  DPL  | S |    GateType   |
//  +---+---+---+---+---+---+---+---+


//  IVT entry:
//  +-----------+-----------+
//  |  Segment  |  Offset   |
//  +-----------+-----------+
//  4           2           0

void* irq_action_vector = 0000;

// IVT Offset | INT #     | Description
// -----------+-----------+-----------------------------------
// 0x0000     | 0x00      | Divide by 0
// 0x0004     | 0x01      | Reserved
// 0x0008     | 0x02      | NMI Interrupt
// 0x000C     | 0x03      | Breakpoint (INT3)
// 0x0010     | 0x04      | Overflow (INTO)
// 0x0014     | 0x05      | Bounds range exceeded (BOUND)
// 0x0018     | 0x06      | Invalid opcode (UD2)
// 0x001C     | 0x07      | Device not available (WAIT/FWAIT)
// 0x0020     | 0x08      | Double fault
// 0x0024     | 0x09      | Coprocessor segment overrun
// 0x0028     | 0x0A      | Invalid TSS
// 0x002C     | 0x0B      | Segment not present
// 0x0030     | 0x0C      | Stack-segment fault
// 0x0034     | 0x0D      | General protection fault
// 0x0038     | 0x0E      | Page fault
// 0x003C     | 0x0F      | Reserved
// 0x0040     | 0x10      | x87 FPU error
// 0x0044     | 0x11      | Alignment check
// 0x0048     | 0x12      | Machine check
// 0x004C     | 0x13      | SIMD Floating-Point Exception
// 0x00xx     | 0x14-0x1F | Reserved
// 0x0xxx     | 0x20-0xFF | User definable

// 
// IVT Offset | INT # | IRQ # | Description
// -----------+-------+-------+------------------------------
// 0x0020     | 0x08  | 0     | PIT
// 0x0024     | 0x09  | 1     | Keyboard
// 0x0028     | 0x0A  | 2     | 8259A slave controller
// 0x002C     | 0x0B  | 3     | COM2 / COM4
// 0x0030     | 0x0C  | 4     | COM1 / COM3
// 0x0034     | 0x0D  | 5     | LPT2
// 0x0038     | 0x0E  | 6     | Floppy controller
// 0x003C     | 0x0F  | 7     | LPT1 

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

void halt()
{
    __asm__ ("hlt");
}

