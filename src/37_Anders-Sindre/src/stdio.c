#include "libc/stdbool.h"
#include "monitor.h"

#define EOF (-1)

// takes int insted of char for backward compatibility
int putchar(int ic) {
    char c = (char) ic;
    monitor_put(c);
	return ic;
}

bool print(const char* data, size_t length) {
	const unsigned char* bytes = (const unsigned char*) data;
	for (size_t i = 0; i < length; i++)
		if (putchar(bytes[i]) == EOF)
			return false;
	return true;
}