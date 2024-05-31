#include "libc/stdint.h"
#include "interrupts.h"

typedef struct {
    int8_t x, y;
    uint8_t left_button, right_button, middle_button;
} mouse_data_t;

void mouse_isr(registers_t* regs);