#include <stddef.h>
#include <stdint.h>

#if defined(__linux__)
#error
#endif

#if !defined(__i386__)
#error "This file needs to be compiled with a ix86-elf compiler"
#endif

#include "../../libc++/cstdio"
#include "vga/vga.hpp"

extern "C"
void kernel_main() {
    terminal_initialize();
    printf("Hi!\n");

    for (int i = -10; i < 10; ++i) {
        printf("Welcome %d + %s", i, "test string");
    }
}

