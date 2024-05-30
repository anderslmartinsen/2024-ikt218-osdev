#ifndef IDT_H
#define IDT_H
#include "libc/stdint.h"

//defining number of interupts in the IDT
#define IDT_ENTRIES 4

//setting up the structure of the table entries
struct idt_entry_t {
  uint16_t base_low;
  uint16_t selector;
  uint8_t zero;
  uint8_t flags;
  uint16_t base_high;
} __attribute__((packed));

//pointer for table
struct idt_ptr_t {
  uint16_t limit;
  uint32_t base;
} __attribute__((packed));

//initializing idt
void idt_load();
void init_idt();

static struct idt_entry_t idt[IDT_ENTRIES];
static struct idt_ptr_t idt_ptr;

#endif