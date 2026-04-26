#include "mist.h"
#define vga ((volatile u16*)0xB8000)

static u16 cursor_x = 0;
static u16 cursor_y = 0;

void cursor_upd(int cursor_x, int cursor_y) {
    u16 pos = cursor_y * 80 + cursor_x;
    outb(0x3D4, 14);
    outb(0x3D5, (u8)(pos >> 8));
    outb(0x3D4, 15);
    outb(0x3D5, (u8)(pos & 0xFF));
}

void clear(void) {
    vga_clear();
    cursor_x = 0;
    cursor_y = 0;
    cursor_upd(0, 0);
}

void putchar(char c) {
    if (c == '\n') {
        cursor_x = 0;
        cursor_y++;
    } else {
        vga_putchar(cursor_x, cursor_y, c);
        cursor_x++;
        if (cursor_x >= 80) {
            cursor_x = 0;
            cursor_y++;
        }
    }
    if (cursor_y >= 25) {
        vga_scrollup();
        cursor_y = 24;
    }
    cursor_upd(cursor_x, cursor_y);
}

void print_str(const char* c) {
    while (*c) {
        putchar(*c);
        c++;
    }
}

void print_dec(u64 i) {
    char* string = u2s(i, str, 10);
    print_str(string);
}

void print_hex(u64 i) {
    char* string = u2s(i, str, 16);
    print_str(string);
}

void print_bin(u64 i) {
    char* string = u2s(i, str, 2);
    print_str(string);
}

void print_oct(u64 i) {
    char* string = u2s(i, str, 8);
    print_str(string);
}
