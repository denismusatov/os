#include <stddef.h>
#include <stdint.h>

#if defined(__linux__)
#error
#endif

#if !defined(__i386__)
#error "This file needs to be compiled with a ix86-elf compiler"
#endif

extern "C"
{
#include "../../libc/include/stdio.h"
}
#include "vga/vga.hpp"

extern "C"
void kernel_main() {
    terminal_initialize();
    printf("Hi!\n");

    for (int i = 0; i < 20; ++i) {
        printf("Welcome\n");
	    putc(i + '0');
	    putc('\n');
    }
}

