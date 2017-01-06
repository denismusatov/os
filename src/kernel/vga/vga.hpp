#ifndef VGA_HPP
#define VGA_HPP

#include <stddef.h>

void terminal_initialize();
void putc(char c);
void terminal_write(const char* data, size_t size);

#endif

