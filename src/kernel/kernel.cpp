// Copyright (c) 2017 Denis Musatov
// 
// Permission is hereby granted, free of charge, to any person obtaining a copy
// of this software and associated documentation files (the "Software"), to deal
// in the Software without restriction, including without limitation the rights
// to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
// copies of the Software, and to permit persons to whom the Software is
// furnished to do so, subject to the following conditions:
// 
// The above copyright notice and this permission notice shall be included in
// all copies or substantial portions of the Software.
// 
// THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
// IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
// FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
// AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
// LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
// OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
// SOFTWARE.

#include <stddef.h>
#include <stdint.h>

#if defined(__linux__)
#error
#endif

#if !defined(__i386__)
#error "This file needs to be compiled with a ix86-elf compiler"
#endif

#include "../../klibc++/cstdio"

extern "C"
{
#include "../../asm/interrupts.h"
}

#include "vga/vga.hpp"

extern "C"
void kernel_main() {
    terminal_initialize();
    kprintf("Hi!\n");

    kprintf("%s", "\n\n\
This FindMax function takes as its first parameter the number of additional\n\
arguments it is going to get. The first additional argument is retrieved and\n\
used as an initial reference for comparison, and then the remaining additional\n\
arguments are retrieved in a loop and compared to return the greatest one\n\
(which in this case is 892).\n");
    kprintf("Interrupts are enabled: %d\n", interrupts_are_enabled());
    enable_interrupts();
    kprintf("Interrupts are enabled: %d\n", interrupts_are_enabled());
}

