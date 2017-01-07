#include <stddef.h>
#include <stdarg.h>
#include <stdbool.h>
#include <limits.h>

#include "../include/stdio.h"
#include "../include/string.h"

extern void terminal_write(const char* data, size_t size);

// Prints to screen integer 'd' and
// returns the number of characters printed
int print_int_(int d) {
    int char_count = 0;

    bool negative = (unsigned int)d & 0x80000000U;
    if (negative) {
        putchar('-');
        d *= -1;
        ++char_count;
    }
    
    int divisor = 10E+8;
    while (d/divisor == 0) {
        divisor /= 10;
        if (divisor == 0) {
            divisor = 1;
            break;
        }
    }

    while (divisor != 0) {
        char digit = (d/divisor) % 10;
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

int print_uint_(unsigned int u) {
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

int printf(const char* format, ...) {
    va_list args;
    va_start(args, format);

    bool percent_observed = false;
    int characters_printed = 0;
    
    size_t length = 0;
    const char* s;
    // double f;
    int i;
    unsigned int u;
    char c;

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
                case 's':
                    s = va_arg(args, const char*);
                    length = strlen(s);
                    characters_printed += length;
                    terminal_write(s, length);
                    break;
                case 'f':
                    // f = va_arg(args, double);
                    // characters_printed += print_float_(f);
                    break;
                case 'd':
                case 'i':
                    i = va_arg(args, int); 
                    characters_printed += print_int_(i);
                    break;
                case 'u':
                    u = va_arg(args, unsigned int);
                    characters_printed += print_uint_(u);
                    break;
                case 'c':
                    c = va_arg(args, int);
                    putchar(c);
                    ++characters_printed;
                    break;
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

