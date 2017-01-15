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
#include <stdarg.h>
#include <stdint.h>
#include <stdbool.h>
#include <limits.h>

#include "../include/stdio.h"
#include "../include/string.h"

extern void terminal_write(const char* data, size_t size);

static int kprint_uint_(uint32_t u);

int kprintf(const char* format, ...) {
    va_list args;
    va_start(args, format);

    bool percent_observed = false;
    int characters_printed = 0;    
    while (*format)
    {
        if (*format == '%') {
            if (percent_observed) {
                // Escape sequence "%%"
                // has to print it as an ordinary '%'
                percent_observed = false;
                // fallthrough
            }
            else {
                percent_observed = true;
                ++format;
                continue;
            }
        }
        if (percent_observed) {
            percent_observed = false;
            // Entered %f, %d, %s, ... etc
            switch (*format)
            {
                case 's': {
                    const char* s = va_arg(args, const char*);
                    size_t length = strlen(s);
                    characters_printed += length;
                    terminal_write(s, length);
                    break;
                }
                case 'f':
                    // f = va_arg(args, double);
                    // characters_printed += print_float_(f);
                    break;
                case 'd':
                case 'i': {
                    int i = va_arg(args, int);
                    if (i < 0) {
                        kputchar('-');
                        ++characters_printed;
                    }
                    characters_printed += kprint_uint_(i);
                    break;
                }
                case 'u': {
                    unsigned int u = va_arg(args, unsigned int);
                    characters_printed += kprint_uint_(u);
                    break;
                }
                case 'c': {
                    int c = va_arg(args, int);
                    kputchar(c);
                    ++characters_printed;
                    break;
                }
            }
            ++format;
            continue;
        }
        kputchar(*format);
        ++characters_printed;
        ++format;
    }
    va_end(args);
    return characters_printed;
}

// Prints to screen unsigned integer 'd' and
// returns the number of characters printed
static int kprint_uint_(uint32_t u) {
    int char_count = 0;

    unsigned int divisor = 10E+8;
    while (u/divisor == 0) {
        divisor /= 10;
        if (divisor == 0) {
            divisor = 1;
            break;
        }
    }

    while (divisor != 0) {
        char digit = (u/divisor) % 10;
        kputchar(digit + '0');
        ++char_count;
        if (divisor == 1) {
            divisor = 0;
            continue;
        }

        divisor /= 10;
        if (divisor == 0)
            divisor = 1;
    }
    return char_count;
}

