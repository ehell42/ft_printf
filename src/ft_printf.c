/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aguiller <aguiller@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/11 18:36:38 by aguiller          #+#    #+#             */
/*   Updated: 2020/03/11 19:45:55 by aguiller         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void    print_init(t_print *new_print)
{

	new_print = (t_print*)malloc(sizeof(t_print));
    new_print->flag = 0;
    new_print->type = 0;
    new_print->next = NULL;
}

void    add_print(t_print *print)
{
    t_print  *new_print;

    new_print = NULL;
    print_init(new_print);
    print->next = new_print;
    
}


int check_letter(va_list list, char format, t_print *print)
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
    va_arg(list, int);
    return (0);
}

int parser(va_list list, char *format)
{
    t_print  *print;

    print = NULL;
    print_init(print);
    while (*format)
    {
        if (*format == '%')
        {
            format++;
            while(check_letter(list, format[0], print))
                format++;
            add_print(print);
        }
        else
        {
            ft_putchar(*format);
            format++;
        }
    }
    va_arg(list, int);
    return (1);
}

int ft_printf(const char *format, ...)
{
    va_list list;
    int     ret;

    va_start(list, (char*)format);
    ret = parser(list, (char*)format);
    va_end(list);
    return (0);     //возвращает 1, если все хорошо, мб по другому?
}
