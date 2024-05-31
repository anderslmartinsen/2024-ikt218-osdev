#include "isr/mouse_isr.h"
#include "libc/stdint.h"
#include "common.h"
#include "libc/stdio.h"

mouse_data_t mouse_data;

void mouse_isr(registers_t* regs) {
    // Read mouse data from the mouse controller
    uint8_t status = inb(0x64);
    if (status & 0x21) {
        uint8_t x = inb(0x60);
        uint8_t y = inb(0x60);

        printf("%d %d\n", x, y);

        // Update mouse movement
        mouse_data.x += (int8_t)x;
        mouse_data.y -= (int8_t)y;

        // Update button states
        mouse_data.left_button = (status & 0x20) ? 1 : 0;
        mouse_data.right_button = (status & 0x10) ? 1 : 0;
        mouse_data.middle_button = (status & 0x08) ? 1 : 0;
    }

    // Send End of Interrupt signal
    outb(0x20, 0x20);
}
