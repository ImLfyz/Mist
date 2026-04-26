# Drivers
Here are x86_64-specific drivers

## Tools
Currently, drivers are available for:
- VGA
- PIC
- Keyboard

### VGA
They are in VGA.c:

|Name                  |What it does                                    |
|:--------------------:|:-----------------------------------------------|
|`vga_clear()`         |Clears the screen without moving cursor         |
|`vga_putchar(x, y, c)`|Puts c to place that have (x, y) coordinates    |
|`vga_getchar(x, y)`   |Returns character that was on (x, y) coordinates|

> But for working with the screen, I recommend using tools from mistd

### PIC
They are in PIC.c:

|Name                                          |What it does                                    |
|:--------------------------------------------:|:-----------------------------------------------|
|`pic_remap(u8 offset_master, u8 offset_slave)`|Remap PIC to safe values                        |
|`pic_send_eoi(u8 irq)`                        |Send end of interrupt signal                    |

### Keyboard
They are in keyboard.c:

|Name                                          |What it does                                                        |
|:--------------------------------------------:|:-------------------------------------------------------------------|
|`kbd_init(void)`                              |Initializes the keyboard and performs required setup                |
|`kbd_handle_irq(u64 error_code)`              |Get scancode from PIC, convert it to letter and put it into a buffer|
|`kbd_getchar(void)`                           |Get and return letter from buffer                                   |
