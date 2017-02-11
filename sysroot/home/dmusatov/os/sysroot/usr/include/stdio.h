
#ifndef STDIO_H
#define STDIO_H

#include <sys/cdefs.h>

#define EOF (-1)

#ifdef __cplusplus
extern "C"
{
#endif

int printf(const char* __restrict format, ...);
extern int putchar(int c);

#ifdef __cplusplus
}
#endif

#endif

