#include "mist.h"

typedef struct {
    u16 offset_low;
    u16 selector;
    u8  ist;
    u8  type_attr;
    u16 offset_mid;
    u32 offset_high;
    u32 reserved;
} __attribute__((packed)) idt_entry;

typedef struct {
    u16 limit;
    u64 base;
} __attribute__((packed)) IDTr;

static idt_entry idt[256];
static IDTr idtr;

static void idt_load(void) {
    idtr.limit = sizeof(idt_entry) * 256 - 1;
    idtr.base  = (u64)&idt;

    __asm__ volatile("lidt %0" : : "m"(idtr));
}

void isr_handler(u8 irq, u64 error_code) __attribute__((used, noinline)) {
    (void)irq; 
    (void)error_code;
    
    __asm__ volatile("cli; hlt");
    
    while(1); 
}

static void idt_set_gate(u8 vector, void* handler, u8 type, u8 dpl) {
    u64 addr = (u64)handler;
    idt[vector].offset_low  = addr & 0xFFFF;
    idt[vector].selector    = 0x08;
    idt[vector].ist         = 0;
    idt[vector].type_attr   = (1 << 7) | (dpl << 5) | type;
    idt[vector].offset_mid  = (addr >> 16) & 0xFFFF;
    idt[vector].offset_high = (addr >> 32) & 0xFFFFFFFF;
    idt[vector].reserved    = 0;
}

extern void isr0(void);  extern void isr1(void);
extern void isr2(void);  extern void isr3(void);
extern void isr4(void);  extern void isr5(void);
extern void isr6(void);  extern void isr7(void);
extern void isr8(void);  extern void isr9(void);
extern void isr10(void); extern void isr11(void);
extern void isr12(void); extern void isr13(void);
extern void isr14(void); extern void isr15(void);
extern void isr16(void); extern void isr17(void);
extern void isr18(void); extern void isr19(void);
extern void isr20(void); extern void isr21(void);
extern void isr22(void); extern void isr23(void);
extern void isr24(void); extern void isr25(void);
extern void isr26(void); extern void isr27(void);
extern void isr28(void); extern void isr29(void);
extern void isr30(void); extern void isr31(void);

void idt_init(void) {
    for (int i = 0; i < 256; i++) idt_set_gate(i, 0, 0, 0);

    void* stubs[32] = {
        isr0, isr1, isr2, isr3, isr4, isr5, isr6, isr7,
        isr8, isr9, isr10, isr11, isr12, isr13, isr14, isr15,
        isr16, isr17, isr18, isr19, isr20, isr21, isr22, isr23,
        isr24, isr25, isr26, isr27, isr28, isr29, isr30, isr31
    };

    for (int i = 0; i < 32; i++) {
        u8 type = (i == 2 || i == 18) ? 0x0E : 0x0F;
        idt_set_gate(i, stubs[i], type, 0);
    }

    idt_load();
    print("\n[ + ]: IDT initialization");
}
