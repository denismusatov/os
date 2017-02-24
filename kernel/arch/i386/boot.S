# Constants for the multiboot header.
.set ALIGN,    1<<0             # align loaded modules on page boundaries
.set MEMINFO,  1<<1             # provide memory map
.set FLAGS,    ALIGN | MEMINFO  # this is the Multiboot 'flag' field
.set MAGIC,    0x1BADB002       # 'magic number' lets bootloader find the header
.set CHECKSUM, -(MAGIC + FLAGS) # checksum of above, to prove we are multiboot

.section .multiboot
.align 4
.long MAGIC
.long FLAGS
.long CHECKSUM

.section .bss
.align 16
stack_bottom:
.skip 16384 # 16 KiB
stack_top:

.section .text
.global _start
.type _start, @function
_start:
    mov $stack_top, %esp

    # Call the global constructors.
    call _init

    # Call initialization function.
    call kernel_early

    # Enter the high-level kernel. The ABI requires the stack is 16-byte
    call kernel_main

    cli
1:    hlt
    jmp 1b

.global gdt_flush
.type gdt_flush, @function
.extern gdtp
gdt_flush:
    lgdt gdtp
    ret

.global setup_idt
.type setup_idt, @function
.extern idt_descr
setup_idt:
    lidt idt_descr
    ret

# Set the size of the _start symbol to the current location '.' minus its start.
# This is useful when debugging or when you implement call tracing.
.size _start, . - _start

