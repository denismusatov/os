
#include "vga.hpp"

#include <stddef.h>
#include <stdint.h>

/* Hardware text mode color constants. */
enum class vga_color {
    black = 0,
    blue = 1,
    green = 2,
    cyan = 3,
    red = 4,
    magenta = 5,
    brown = 6,
    lignt_grey = 7,
    dark_grey = 8,
    light_blue = 9,
    lignt_green = 10,
    lignt_cyan = 11,
    lignt_red = 12,
    light_magenta = 13,
    light_brown = 14,
    white = 15,
};

static inline uint8_t vga_entry_color(vga_color fg,
                                      vga_color bg) {
    return static_cast<uint8_t>(fg) | static_cast<uint8_t>(bg) << 4;
}

static inline uint16_t vga_entry(unsigned char uc, uint8_t color) {
    return static_cast<uint16_t>(uc) | static_cast<uint16_t>(color) << 8;
}


static const size_t VGA_WIDTH = 80;
static const size_t VGA_HEIGHT = 25;

size_t terminal_row;
size_t terminal_column;
uint8_t terminal_color;
uint16_t* terminal_buffer;

void terminal_initialize() {
    terminal_row = 0;
    terminal_column = 0;
    terminal_color = vga_entry_color(vga_color::white, vga_color::black);
    terminal_buffer = (uint16_t*) 0xB8000;
    for (size_t y = 0; y < VGA_HEIGHT; y++) {
        for (size_t x = 0; x < VGA_WIDTH; x++) {
            const size_t index = y * VGA_WIDTH + x;
            terminal_buffer[index] = vga_entry(' ', terminal_color);
        }
    }
}

void terminal_scroll_up()
{
    for (size_t i = 1; i < VGA_HEIGHT; ++i) {
        for (size_t j = 0; j < VGA_WIDTH; ++j) {
            const size_t index = (i - 1)*VGA_WIDTH + j; 
            terminal_buffer[index] = terminal_buffer[index + VGA_WIDTH];
        }
    }
    --terminal_row;
    for (size_t i = 0; i < VGA_WIDTH; ++i)
        terminal_buffer[(VGA_HEIGHT - 1)*VGA_WIDTH + i] &= (0xFF00 | static_cast<uint16_t>(' '));
}

void terminal_setcolor(uint8_t color) {
    terminal_color = color;
}

void terminal_putentryat(char c, uint8_t color, size_t x, size_t y) {
    const size_t index = y * VGA_WIDTH + x;
    terminal_buffer[index] = vga_entry(c, color);
}

extern "C" 
int putchar(int c) {
    if (c == '\n') {	
        terminal_column = 0;
        ++terminal_row;
    }
    else {
        terminal_putentryat(c, terminal_color, terminal_column, terminal_row);
        if (++terminal_column == VGA_WIDTH) {
            terminal_column = 0;
            ++terminal_row;
        }
    }
    if (terminal_row == VGA_HEIGHT)
        terminal_scroll_up();
    return c;
}

extern "C"
void terminal_write(const char* data, size_t size) {
    for (size_t i = 0; i < size; i++)
        putchar(data[i]);
}

