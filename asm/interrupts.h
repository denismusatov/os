#ifndef INTERRUPTS_H
#define INTERRUPTS_H

#include <stdbool.h>

bool interrupts_are_enabled();
void enable_interrupts();
void disable_interrupts();

void halt();

#endif

