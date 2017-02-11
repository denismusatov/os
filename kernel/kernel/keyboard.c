
#include "keyboard.h"

#include "../../asm/io.h"
#include "scan_set1.h"

/*
 * PS/2 keyboard code.
 * Dependencies:
 * inb function and scancode table.
 * */
static char getScancode()
{
    char c = 0;
    do {
       // if (inb(0x60) != c)
        {
         //   c = inb(0x60);
            if (c > 0)
                return c;
        }
    } while(1);
}

char getchar()
{
    return getScancode();
    // return scancode[(int)getScancode()];
}

