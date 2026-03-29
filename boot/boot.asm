bits 16
org 0x7C00

jmp start
nop

start:
    cli
    xor ax, ax
    mov ds, ax
    mov es, ax
    mov ss, ax
    mov sp, 0x7C00

    in al, 0x92
    or al, 2
    out 0x92, al

    lgdt [gdt_ptr]

    mov eax, cr0
    or al, 1
    mov cr0, eax
    jmp 0x08:pm_entry

bits 32
pm_entry:
    mov ax, 0x10
    mov ds, ax
    mov es, ax
    mov ss, ax
    mov esp, 0x90000

    mov edi, 0xB8000
    mov ecx, 2000
    mov ax, 0x0720
    cld
    rep stosw

    mov edi, 0x1000
    mov cr3, edi
    
    mov dword [edi], 0x2003
    mov dword [edi + 4], 0
    
    mov edi, 0x2000
    mov ebx, 0x00000083
    mov ecx, 512
.pd_loop:
    mov dword [edi], ebx
    mov dword [edi + 4], 0
    add ebx, 0x200000
    add edi, 8
    loop .pd_loop

    mov byte [gdt_start + 14], 00100000b

    mov eax, cr4
    or eax, 1 << 5
    mov cr4, eax

    mov ecx, 0xC0000080
    rdmsr
    or eax, 1 << 8
    wrmsr

    mov eax, cr0
    or eax, 1 << 31
    mov cr0, eax

    jmp 0x08:lm_entry

bits 64
lm_entry:
    mov ax, 0x10
    mov ds, ax
    mov es, ax
    mov ss, ax
    mov rsp, 0x90000

    mov esi, welcome_msg
    mov edi, 0xB8000
    mov ecx, welcome_len
.print_loop:
    lodsb
    mov [edi], al
    mov byte [edi + 1], 0x0A
    add edi, 2
    loop .print_loop

    cli
.halt:
    hlt
    jmp .halt

welcome_msg:
    db "Welcome to Mist!", 0
welcome_len equ $ - welcome_msg

gdt_start:
    dq 0
gdt_code:
    dw 0xFFFF
    dw 0
    db 0
    db 10011010b
    db 01001111b
    db 0
gdt_
    dw 0xFFFF
    dw 0
    db 0
    db 10010010b
    db 00000000b
    db 0
gdt_end:

gdt_ptr:
    dw gdt_end - gdt_start - 1
    dd gdt_start

times 510 - ($ - $$) db 0
dw 0xAA55
