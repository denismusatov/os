
#include <stddef.h>
#include <stdarg.h>
#include <stdint.h>
#include <stdbool.h>
#include <limits.h>

#include <stdio.h>
#include <string.h>

extern void terminal_write(const char* data, size_t size);

static int print_uint(uint32_t u);

int printf(const char* format, ...) {
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
                        putchar('-');
                        ++characters_printed;
                    }
                    characters_printed += print_uint(i);
                    break;
                }
                case 'u': {
                    unsigned int u = va_arg(args, unsigned int);
                    characters_printed += print_uint(u);
                    break;
                }
                case 'c': {
                    int c = va_arg(args, int);
                    putchar(c);
                    ++characters_printed;
                    break;
                }
            }
            ++format;
            continue;
        }
        putchar(*format);
        ++characters_printed;
        ++format;
    }
    va_end(args);
    return characters_printed;
}

// Prints to screen unsigned integer 'd' and
// returns the number of characters printed
static int print_uint(uint32_t u) {
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
        putchar(digit + '0');
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

