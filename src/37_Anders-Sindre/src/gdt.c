#include "descriptor_tables.h"

// Defined in gdt.asm
extern void gdt_flush(uint32_t gdt_ptr);

// Initialised the gdt
void init_gdt()
{
  // Sets the gdt_ptr limit and base
    gdt_ptr.limit = sizeof(struct gdt_entry) * GDT_ENTRIES - 1;
    gdt_ptr.base = (uint32_t) &gdt;

    // num, base, limit, access, granularity 
    gdt_set_gate(0, 0, 0, 0, 0);                // Null segment
    gdt_set_gate(1, 0, 0xFFFFFFFF, 0x9A, 0xCF); // Code segment
    gdt_set_gate(2, 0, 0xFFFFFFFF, 0x92, 0xCF); // Data segment
    gdt_set_gate(3, 0, 0xFFFFFFFF, 0xFA, 0xCF); // User mode code segment
    gdt_set_gate(4, 0, 0xFFFFFFFF, 0xF2, 0xCF); // User mode data segment

    // Load the GDT
    gdt_load(&gdt_ptr);
	
	// Flush GDT pointer
	gdt_flush((uint32_t)&gdt_ptr);
}

void gdt_load(struct gdt_ptr *gdt_ptr) {
  // Used the lgdt funksjon to give the prossessor GDT register the gdt_ptr pointer
  asm volatile("lgdt %0" : : "m" (*gdt_ptr));
}

void gdt_set_gate(int32_t num, uint32_t base, uint32_t limit, uint8_t access, uint8_t gran)
{
    gdt[num].base_low    = (base & 0xFFFF);       // Sets the lower 16 bits of the memory address
    gdt[num].base_middle = (base >> 16) & 0xFF;   // Sets the next 8 bits of the memory address
    gdt[num].base_high   = (base >> 24) & 0xFF;   // Sets the upper 8 bits of the memory address

    gdt[num].limit_low   = (limit & 0xFFFF);      // Sets the lower 16 bits of the limit
    gdt[num].granularity = (limit >> 16) & 0x0F;  // Sets the upper 4 bits of limit

    gdt[num].granularity |= gran & 0xF0;          // Sets the gran flags
    gdt[num].access      = access;                // Sets the access level
}