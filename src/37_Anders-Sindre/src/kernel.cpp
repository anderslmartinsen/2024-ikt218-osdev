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

    register_interrupt_handler(2, [](registers_t* regs, void* context) {
        printf("Interrupt 2 - OK\n");
    }, NULL);

    register_interrupt_handler(3, [](registers_t* regs, void* context) {
        printf("Interrupt 3 - OK\n");
    }, NULL);

    register_irq_handler(IRQ1, [](registers_t*, void*) {
        // Read from keyboard
        unsigned char scan_code = inb(0x60);
        char f = scancode_to_ascii(&scan_code);
        printf("\n");
        printf("%d %c :D \n", f, f);

        // Disable
        asm volatile("cli");
    }, NULL);

    register_irq_handler(IRQ12, [](registers_t* regs, void*)  {
        printf("hello :D");
        //mouse movement
        unsigned char scan_code = inb(0x60);
        mouse_isr(regs);
    }, NULL);

    asm volatile("sti");

    asm volatile ("int $0x3");
    asm volatile ("int $0x3");
    asm volatile ("int $0x3");

    asm volatile ("int $0x60");


    while (true)
    {
        // 
    }
    
    return 0;
}