#include "common.h"

// writes a byte to a specefied I/O port. %1, and %0 get extanged by "dN" (port) and "a" (value)
// "dN" tells the compiler that (port) should be passed to a register for I/O port access
// "a" tells the compiler that (value) should be passed to the 'eax' register. 
void outb(uint16_t port, uint8_t value)
{
    asm volatile ("outb %1, %0" : : "dN" (port), "a" (value));
}