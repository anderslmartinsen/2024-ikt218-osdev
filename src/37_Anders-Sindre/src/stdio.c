#include "libc/stdio.h"
#include "libc/stdbool.h"
#include "libc/stdint.h"

bool print(const char* data, size_t length)
{
    int row = 0;
    int offset = 0;
    char* video_memory = (char*)0xb8000;
    while (*data)
    {
        if (*data == '\n')
        {
            row++;
            offset = (row * 80) * 2;
            data++;
            continue;
        }

        video_memory[offset++] = *data++;
        video_memory[offset++] = 0x0F;
    }
    return 0;
}
