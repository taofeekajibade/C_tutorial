#include <stdio.h>
#include <stdarg.h>

void my_printf(const char *format, ...) {
    va_list args;
    va_start(args, format);

    while (*format != '\0') {
        if (*format == '%') {
            format++; // Move past '%'
            switch (*format) {
                case 'c': {
                    char c = (char)va_arg(args, int);
                    putchar(c);
                    break;
                }
                case 's': {
                    char *str = va_arg(args, char*);
                    while (*str != '\0') {
                        putchar(*str);
                        str++;
                    }
                    break;
                }
                case 'd': {
                    int num = va_arg(args, int);
                    printf("%d", num);
                    break;
                }
                case 'x': {
                    int num = va_arg(args, int);
                    printf("%x", num);
                    break;
                }
                default:
                    putchar(*format);
                    break;
            }
        } else {
            putchar(*format);
        }
        format++;
    }

    va_end(args);
}

int main() {
    char ch = 'A';
    char str[] = "Hello, world!";
    int num = 42;
    int hex_num = 0x1A;

    my_printf("Character: %c\n", ch);
    my_printf("String: %s\n", str);
    my_printf("Decimal: %d\n", num);
    my_printf("Hexadecimal: %x\n", hex_num);

    return 0;
}
