extern "C"{
    #include "libc/stdio.h"
    #include "common.h"
    #include "interrupts.h"
    #include "libc/stddef.h"
    #include "input.h"
    #include "isr/mouse_isr.h"
}


extern "C" int kernel_main(void);
int kernel_main(){

    register_interrupt_handler(ISR1, [](registers_t* regs, void* context) {
        printf("Interrupt 1 - OK\n");
    }, NULL);

    register_interrupt_handler(ISR2, [](registers_t* regs, void* context) {
        printf("Interrupt 2 - OK\n");
    }, NULL);

    register_interrupt_handler(ISR3, [](registers_t* regs, void* context) {
        printf("Interrupt 3 - OK\n");
    }, NULL);

    register_irq_handler(IRQ1, [](registers_t*, void*) {
        // Read from keyboard
        unsigned char scan_code = inb(0x60);
        // Convert scan_code to ASCII char
        char f = scancode_to_ascii(&scan_code);
        // Print ASCII value and char
        printf("ASCII value: %d, ASCII char %c\n", f, f);

        // Disable
        asm volatile("cli");
    }, NULL);

    asm volatile("sti");

    // Trigger IRS1
    asm volatile ("int $0x1");
    // Trigger IRS2
    asm volatile ("int $0x2");
    // Trigger IRS3
    asm volatile ("int $0x3");

    


    while (true)
    {
        // 
    }
    
    return 0;
}