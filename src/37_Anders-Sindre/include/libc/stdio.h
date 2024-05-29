#pragma once
#include "libc/stdbool.h"
#include "libc/stdint.h"

// put char on screen, 
int putchar(int ic);
// prints multiple char to the screen
bool print(const char* data, size_t length);
int printf(const char* __restrict__ format, ...);