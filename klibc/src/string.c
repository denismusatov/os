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

#include "../include/string.h"

#include <stddef.h>

void* memcpy(void* dest, const void* source, size_t num) {
    for (size_t i = 0; i < num; ++i) {
        ((unsigned char*)source)[i] = ((unsigned char*)dest)[i];
    }
    return dest;
}

void* wmemcpy(void* dest, const void* source, size_t num) {
    for (size_t i = 0; i < num; ++i) {
        ((wchar_t*)source)[i] = ((wchar_t*)dest)[i];
    }
    return dest;
}

void* memset(void* ptr, int value, size_t num) {
    for (size_t i = 0; i < num; ++i) {
        ((unsigned char*)ptr)[i] = (unsigned char)value;
    }
    return ptr;
}

void* wmemset(void* ptr, int value, size_t num) {
    for (size_t i = 0; i < num; ++i) {
        ((wchar_t*)ptr)[i] = (wchar_t)value;
    }
    return ptr;
}

size_t strlen(const char* str) {
    size_t len = 0;
    while (str[len])
        len++;
    return len;
}



