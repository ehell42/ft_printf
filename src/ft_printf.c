/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alexzudin <alexzudin@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/11 18:36:38 by aguiller          #+#    #+#             */
/*   Updated: 2020/03/20 10:42:12 by alexzudin        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

t_print    *clear_init(t_print *new_print)
{
    new_print->flag = 0;
    new_print->type = 0;
    new_print->width = 0;
    new_print->precision = 0;
    return (new_print);
}

void work_with_print(t_print *print, va_list list)
{
    char a;
    
    a = print->type;
    va_end(list);
}

int check_letter(char **format, t_print *print)
{
    if (**format == 'd' || **format == 'f' || **format == 'c' || **format == 's' || **format == 'o' || **format == 'x' || **format == 'X' || **format == 'F' || **format == 'p')
        return(checkforextra('t', format, print));
    if (**format == '+' || **format == '-' || **format == '%' || **format == ' ' 
    || **format == '#' || **format == '0')
        return (checkforextra('f',format, print));
    if ((**format >= '0' && **format <= '9') || **format == '*')
        return (checkforextra('w', format, print));
    if (**format == '.' && **(format + 1))
        return (checkforextra('p', format, print));
    return (exits("invalid letter", print));
}


int parser(va_list list, char *format, int count)
{
    t_print  *print;

    print = NULL;
    print = print_init(print);
    while (*format != '\0')
    {
        if (*format == '%')
        {
            format++;
            while (check_letter((&format), print) && *format)
                continue;
            work_with_print(print, list);
            clear_init(print);
        }
        else
        {
            ft_putchar(*format);
            count++;
            format++;
        }
    }
    return (1);
}

int ft_printf(const char *format, ...)
{
    int count;
    va_list list;
    int     ret;

    count = 0;
    va_start(list, (char*)format);
    ret = parser(list, (char*)format, count);
    //va_end(list);
    return (count);
}
