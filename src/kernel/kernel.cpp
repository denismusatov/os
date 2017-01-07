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

    printf("%s", "\n\n\
This FindMax function takes as its first parameter the number of additional\n\
arguments it is going to get. The first additional argument is retrieved and\n\
used as an initial reference for comparison, and then the remaining additional\n\
arguments are retrieved in a loop and compared to return the greatest one\n\
(which in this case is 892).");

}

