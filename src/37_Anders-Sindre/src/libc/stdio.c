#include "libc/stdbool.h"
#include "monitor.h"

#define EOF (-1)

// takes int insted of char for backward compatibility
int putchar(int ic) {
	// converts the int to char
    char c = (char) ic;
	// prints to the screen
    monitor_put(c);
	// Returs the input
	return ic;
}

// prints a multiple char to screen
bool print(const char* data, size_t length) {
	const unsigned char* bytes = (const unsigned char*) data;
	// Calls putchar for every char in bytes, if putchar returns -1 it returns false, else it returns true after it has 
	// printed bytes
	for (size_t i = 0; i < length; i++)
		if (putchar(bytes[i]) == EOF)
			return false;
	return true;
}