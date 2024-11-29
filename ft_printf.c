#include "stdarg.h"
#include <stdio.h>
int ft_putchar(char c);

int check(char c,va_list args)
{
    if (c == 'c')
        ft_putchar(va_arg(args, int));
    if (c == 'd')
        printf("%d\n", va_arg(args, int));
}

int ft_printf(const char *format, ...)
{
    va_list args;
    va_start(args,format);

    unsigned int i;
    unsigned int result;

    i = 0;
    result = 0;
    while (format[i])
    {
        if (format[i] == '%') {
            result += check(format[++i],args);
            i++;
        }
        else
            result += ft_putchar(format[i++]);

    }    

    va_end(args);
    return (result);
}