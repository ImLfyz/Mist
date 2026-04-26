#pragma once

extern volatile u8 kbd_scancode;
extern volatile bool kbd_ready;

bool idt_init(void);
void isr_handler(u8 vector, u64 error_code);
void idt_set_gate(u8 vector, void* handler, u8 type, u8 dpl);
