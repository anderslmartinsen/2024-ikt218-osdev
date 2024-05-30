#ifndef DESCRIPTOR_TABLES_H
#define DESCRIPTOR_TABLES_H

#include "libc/stdint.h"

// How many entryes we want in the gdt array
#define GDT_ENTRIES 5
// How many entryes we want in the idt array
#define IDT_ENTRIES 256

struct gdt_entry {
  uint16_t limit_low;
  uint16_t base_low;
  uint8_t base_middle;
  uint8_t access;
  uint8_t granularity;
  uint8_t base_high;
} __attribute__((packed));

struct idt_entry {
  uint16_t base_low;
  uint16_t selector;
  uint8_t zero;
  uint8_t flags;
  uint16_t base_high;
} __attribute__((packed));

struct gdt_ptr {
  uint16_t limit;
  uint32_t base;
} __attribute__((packed));

struct idt_ptr {
  uint16_t limit;
  uint32_t base;
} __attribute__((packed));

void init_gdt();
void init_idt();

void gdt_load(struct gdt_ptr *gdt_ptr);
void idt_load();

void gdt_set_gate(int32_t num, uint32_t base, uint32_t limit, uint8_t access, uint8_t gran);



static struct idt_entry idt[IDT_ENTRIES];
static struct idt_ptr idt_ptr;
// Makes an array based on gdt_entry
static struct gdt_entry gdt[GDT_ENTRIES];
// makes a instance of gdt_ptr
static struct gdt_ptr gdt_ptr;

#endif