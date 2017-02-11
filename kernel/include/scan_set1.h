

char scancode[256] = { -1 /* 0x00 */,
    -1 /* ESCAPE 0x01 */, '1', '2', '3', '4', '5', '6', '7', '8', '9', '0', '-', '=', -1 /* BACKSPACE */,
    '\t', 'q', 'w', 'e', 'r', 't', 'y', 'u', 'i', 'o', 'p', '[', ']', -1 /* ENTER pressed */, -1 /* LEFT CONTROL pressed*/,
    'a', 's', 'd', 'f', 'g', 'h', 'j', 'k', 'l', ';', '\'', '`', -1 /* LEFT SHIFT pressed */, '\\',
    'z', 'x', 'c', 'v', 'b', 'n', 'm', ',', '.', '/', -1 /* RIGHT SHIFT pressed */, '*' /*  keypad pressed */,
    -1 /* LEFT ALT pressed */, ' ', -1 /* CAPS LOCK pressed */,
    -1 /* F1 pressed */,
    -1 /* F2 pressed */,
    -1 /* F3 pressed */,
    -1 /* F4 pressed */,
    -1 /* F5 pressed */,
    -1 /* F6 pressed */,
    -1 /* F7 pressed */,
    -1 /* F8 pressed */,
    -1 /* F9 pressed */,
    -1 /* F10 pressed */,
    -1 /* Number Lock pressed */,
    -1 /* Scroll Lock pressed */,

    /* KEYPAD pressed */
    '7',
    '8',
    '9',
    '-',
    '4',
    '5',
    '6',
    '+',
    '1',
    '2',
    '3',
    '0',
    '.',
    /* END KEYPAD */
    -1 /* F11 pressed */,
    -1 /* F12 pressed */

    /* RELEASED */

    /*0x81    escape released    0x82    1 released    0x83    2 released
    0x84    3 released    0x85    4 released    0x86    5 released    0x87    6 released
    0x88    7 released    0x89    8 released    0x8A    9 released    0x8B    0 (zero) released
    0x8C    - released    0x8D    = released    0x8E    backspace released    0x8F    tab released
    0x90    Q released    0x91    W released    0x92    E released    0x93    R released
    0x94    T released    0x95    Y released    0x96    U released    0x97    I released
    0x98    O released    0x99    P released    0x9A    [ released    0x9B    ] released
    0x9C    enter released    0x9D    left control released    0x9E    A released    0x9F    S released
    0xA0    D released    0xA1    F released    0xA2    G released    0xA3    H released
    0xA4    J released    0xA5    K released    0xA6    L released    0xA7     ; released
    0xA8    ' (single quote) released    0xA9    ` (back tick) released    0xAA    left shift released    0xAB    \ released
    0xAC    Z released    0xAD    X released    0xAE    C released    0xAF    V released
    0xB0    B released    0xB1    N released    0xB2    M released    0xB3    , released
    0xB4    . released    0xB5    / released    0xB6    right shift released    0xB7    (keypad) * released
    0xB8    left alt released    0xB9    space released    0xBA    CapsLock released    0xBB    F1 released
    0xBC    F2 released    0xBD    F3 released    0xBE    F4 released    0xBF    F5 released
    0xC0    F6 released    0xC1    F7 released    0xC2    F8 released    0xC3    F9 released
    0xC4    F10 released    0xC5    NumberLock released    0xC6    ScrollLock released    0xC7    (keypad) 7 released
    0xC8    (keypad) 8 released    0xC9    (keypad) 9 released    0xCA    (keypad) - released    0xCB    (keypad) 4 released
    0xCC    (keypad) 5 released    0xCD    (keypad) 6 released    0xCE    (keypad) + released    0xCF    (keypad) 1 released
    0xD0    (keypad) 2 released    0xD1    (keypad) 3 released    0xD2    (keypad) 0 released    0xD3    (keypad) . released
    0xD7    F11 released
    0xD8    F12 released                        
    0xE0, 0x1C    (keypad) enter pressed    0xE0, 0x1D    right control pressed                
    0xE0, 0x35    (keypad) / pressed                
    0xE0, 0x38    right alt (or altGr) pressed                        
    0xE0, 0x47    home pressed
    0xE0, 0x48    cursor up pressed    0xE0, 0x49    page up pressed            0xE0, 0x4B    cursor left pressed
    0xE0, 0x4D    cursor right pressed            0xE0, 0x4F    end pressed
    0xE0, 0x50    cursor down pressed    0xE0, 0x51    page down pressed    0xE0, 0x52    insert pressed    0xE0, 0x53    delete pressed
    0xE0, 0x5B    left GUI pressed
    0xE0, 0x5C    right GUI pressed    0xE0, 0x5D    "apps" pressed                
    0xE0, 0x9C    (keypad) enter released    0xE0, 0x9D    right control released                
    0xE0, 0xB5    (keypad) / released                
    0xE0, 0xB8    right alt (or altGr) released                        
    0xE0, 0xC7    home released
    0xE0, 0xC8    cursor up released    0xE0, 0xC9    page up released            0xE0, 0xCB    cursor left released
    0xE0, 0xCD    cursor right released            0xE0, 0xCF    end released
    0xE0, 0xD0    cursor down released    0xE0, 0xD1    page down released    0xE0, 0xD2    insert released    0xE0, 0xD3    delete released
    0xE0, 0xDB    left GUI released
    0xE0, 0xDC    right GUI released    0xE0, 0xDD    "apps" released                
    0xE0, 0x2A, 0xE0, 0x37    print screen pressed
    0xE0, 0xB7, 0xE0, 0xAA    print screen released
    0xE1, 0x1D, 0x45, 0xE1, 0x9D, 0xC5    pause pressed*/
};


