#include "libc/stdint.h"
#include "libc/stddef.h"
#include "libc/stdbool.h"
#include "libc/string.h"
#include "libc/stdio.h"
#include "gdt.h"
#include <multiboot2.h>

#include "monitor.h"


struct multiboot_info {
    uint32_t size;
    uint32_t reserved;
    struct multiboot_tag *first;
};

int kernel_main();


int main(uint32_t magic, struct multiboot_info* mb_info_addr) {
    monitor_initialize();

    init_gdt();

    printf("Hello, World! %d", 10);

    

    // Call cpp kernel_main (defined in kernel.cpp)
    return kernel_main();
}