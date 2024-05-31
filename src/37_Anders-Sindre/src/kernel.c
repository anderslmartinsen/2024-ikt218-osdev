#include "libc/stdint.h"
#include "libc/stddef.h"
#include "libc/stdbool.h"
#include "libc/string.h"
#include "libc/stdio.h"
#include "descriptor_tables.h"
#include <multiboot2.h>
#include "interrupts.h"
#include "monitor.h"


struct multiboot_info {
    uint32_t size;
    uint32_t reserved;
    struct multiboot_tag *first;
};

int kernel_main();


int main(uint32_t magic, struct multiboot_info* mb_info_addr) {
    // Inizialises the monitor
    monitor_initialize();
    // Inizialises GDT
    init_gdt();
    // Inizialises IDT
    init_idt();
    // Inizialises IRQ
    init_irq();

    printf("Hello, World!\n");

    // Call cpp kernel_main (defined in kernel.cpp)
    return kernel_main();
}