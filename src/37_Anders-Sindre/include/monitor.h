#ifndef MONITOR_H
#define MONITOR_H

#include "libc/stdint.h"
#include "libc/stddef.h"

// Initializes the screen parameters and video memory
void monitor_initialize() ;
// Sets the monitor color
void monitor_setcolor(uint8_t color);

// puts a character on the monitor
void monitor_put(char c);
// Clears the monitor
void monitor_clear();
// Writes multiple chars to the monitor
void monitor_write(const char* data, size_t size);



#endif