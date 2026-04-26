#pragma once

static inline void outb(u16 port, u8 val) {
    __asm__ volatile("outb %0, %1" : : "a"(val), "d"(port));
}
static inline u8 inb(u16 port) {
    u8 res;
    __asm__ volatile("inb %1, %0" : "=a"(res) : "d"(port));
    return res;
}
void pic_remap(u8 offset_master, u8 offset_slave);
void pic_send_eoi(u8 irq);
