#pragma once
#include "types.h"

void cursor_upd(int cursor_x, int cursor_y);
void clear(void);
void putchar(char i);
void print_str(const char* c);
void print_dec(u64 i);
void print_hex(u64 i);
void print_bin(u64 i);
void print_oct(u64 i);
