#include "mist.h"

void __attribute__((section(".text.start"), noreturn)) main(void) {
    clear();
    print_str("                         @#");
    print_str("\n              %(        }##");
    print_str("\n             ##>       <#:#");
    print_str("\n            #01#      ## ##");
    print_str("\n           &# ##     ##  <>");
    print_str("\n          #?  ##    ##    /n");
    print_str("\n         >#    ##  ##      [#");
    print_str("\n        #@     (# #)        #^");
    print_str("\n      ?*        -_-          #*#");
    print_str("\n    #&                        $##%");
    print_str("\n  <#                            #0#1");
    print_str("\n#@                                #+#=]");
    print_str("\n                                    {#!#}");
    print_str("\n                                      ?#@;#{");
    print_str("\n -- Welcome to Mist!");
    print_str("\n\nStarting...");

    if (!pmm_init()) {
        print_str("\n[FAIL]: PMM initialization");
        print_str("\n[WARN]: System halted. Reboot required");
        for (;;) __asm__ volatile("hlt");
    } else {
        print_str("\n[ OK ]: PMM initialization");
    }

    if (!vmm_init()) {
        print_str("\n[FAIL]: VMM initialization");
        print_str("\n[WARN]: System halted. Reboot required");
        for (;;) __asm__ volatile("hlt");
    } else {
        print_str("\n[ OK ]: VMM initialization");
    }

    if (!idt_init()) {
        print_str("\n[FAIL]: IDT initialization");
        print_str("\n[WARN]: System halted. Reboot required");
        for (;;) __asm__ volatile("hlt");
    } else {
        print_str("\n[ OK ]: IDT initialization");
    }

    pic_remap(0x20, 0x28);
    kbd_init();

    __asm__ volatile("sti");

    print_str("\n_> ");

    while (1) {
        char c = kbd_getchar();
        if (c == '\b') {
            print_str("<BS>");
        } else if (c == '\n') {
            putchar(c);
            print_str("_> ");
        } else if (c >= 0x20 && c <= 0x7E) {
            putchar(c);
        }
}

    for (;;) __asm__ volatile("hlt");
}
