extern "C"{
    #include "var.h"
    #include "interrupts.h"
    #include "ascii_table.h"
    #include "libc/stddef.h"
    #include "libc/stdio.h"
}

extern "C" int kernel_main(void);
int kernel_main(){

    // Set up interrupt handlers
    register_interrupt_handler(0, [](registers_t* regs, void* context) {
        printf("Interrupt 0 - OK\n");
    }, NULL);

    register_interrupt_handler(1, [](registers_t* regs, void* context) {
        printf("Interrupt 1 - OK\n");
    }, NULL);

    register_interrupt_handler(2, [](registers_t* regs, void* context) {
        printf("Interrupt 2 - OK\n");
    }, NULL);

    asm volatile ("int $0x0"); // Generate interrupt 0
    asm volatile ("int $0x1"); // Generate interrupt 1
    asm volatile ("int $0x2"); // Generate interrupt 2


printf("hi");
printf("123");

    asm volatile("sti");

// Register IRQ handler for keyboard (IRQ1)
    register_irq_handler(IRQ1, [](registers_t*, void*) {
        // Read from keyboard
        unsigned char scan_code = inb(0x60);
        char f = scancode_to_ascii(&scan_code);
        printf("\n");
        printf("%d", f);

        printf("working :D \n");

        // Disable
        asm volatile("cli");
    }, NULL);

    printf("Kernel main loop\n");
    int i = 0;
    while(true) {
        i++;
    }

    printf("youll never see me(hopefully)");
    return 0;
}