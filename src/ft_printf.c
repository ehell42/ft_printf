#include "ft_printf.h"

void    print_init(struct t_print *new_print)
{
    new_print->flag = 0;
    new_print->type = 0;
    new_print->next = NULL;
}

void    add_print(struct t_print *print)
{
    struct t_print  *new_print;

    print_init(new_print);
    print->next = new_print;
    
}

int check_letter(va_list list, str *format, struct t_print *print)
{
    if (format == 'd' || format == 'f' || format == 'c' || format == 's'
    || format == 'o' || format == 'x' || format == 'X' || format == 'F' || format == 'p')
    {
        print->type = format;
        return (1);
    }
    else if (format == '+' || format == '-' || format == '%')
    {
        print->flag = format;
        return (1);
    }
    return (0);
}

int parser(va_list list, str *format)
{
    int             n;
    struct t_print  *print;

    print_init(print);
    while (*format)
    {
        if (format == '%')
        {
            format++;
            if (check_letter(list, format, print) == 0)
                return (0);
            add_print(print);
            format++;
        }
        else
        {
            if (check_letter(list, format, print) == 0)
                return (0);
            add_print(print);
            format++;
        }
    }
    return (1);
}

int ft_printf(const char *format, ...)
{
    va_list list;
    int     ret;

    va_start(list, format);
    ret = parser(list, format);
    va_end(list);
    return (n);     //возвращает 1, если все хорошо, мб по другому?
}