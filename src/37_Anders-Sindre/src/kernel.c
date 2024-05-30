#include "libc/stdint.h"
#include "libc/stddef.h"
#include "libc/stdbool.h"
#include "libc/string.h"
#include "libc/stdio.h"
#include "gdt.h"
#include "idt.h"
#include <multiboot2.h>
#include "var.h"
#include "interrupts.h"
#include "monitor.h"


struct multiboot_info {
    uint32_t size;
    uint32_t reserved;
    struct multiboot_tag *first;
};

int kernel_main();


int main(uint32_t magic, struct multiboot_info* mb_info_addr) {
    init_gdt();
    init_idt();
    init_interrupts();
    init_irq();

    monitor_initialize();

    printf("Hello world! :D\n");
    printf("what");

    // Call cpp kernel_main (defined in kernel.cpp)
    return kernel_main();

    printf(":(");
}