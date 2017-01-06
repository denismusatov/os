#include <stddef.h>
#include <stdint.h>

#if defined(__linux__)
#error
#endif

#if !defined(__i386__)
#error "This file needs to be compiled with a ix86-elf compiler"
#endif

#include "../../libc/include/string.h"

#include "vga/vga.hpp"


void printf(const char* data) {
    terminal_write(data, strlen(data));
}


extern "C"
void kernel_main() {
    terminal_initialize();
    printf("Hi!\n");

    for (int i = 0; i < 10; ++i) {
        printf("Welcome\n");
	    putc(i + '0');
	    putc('\n');
    }
}

