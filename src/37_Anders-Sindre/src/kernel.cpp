extern "C"{
    #include "var.h"
    #include "interrupts.h"
    #include "ascii_table.h"
    #include "libc/stddef.h"
}

extern "C" int kernel_main(void);
int kernel_main(){
// Register IRQ handler for keyboard (IRQ1)
    register_irq_handler(IRQ1, [](registers_t*, void*) {
        // Read from keyboard
        unsigned char scan_code = inb(0x60);
        char f = scancode_to_ascii(&scan_code);

        //printf("%c", f);
        

        // Disable
        asm volatile("cli");
    }, NULL);

    return 0;
}