/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alexzudin <alexzudin@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/11 18:36:38 by aguiller          #+#    #+#             */
/*   Updated: 2020/03/17 09:33:01 by alexzudin        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

t_print    *print_init(t_print *new_print)
{

	new_print = (t_print*)malloc(sizeof(t_print));
    new_print->flag = 0;
    new_print->type = 0;
    new_print->width = 0;
    new_print->precision = 0;
    return (new_print);
}

t_print    *clear_init(t_print *new_print)
{
    new_print->flag = 0;
    new_print->type = 0;
    new_print->width = 0;
    new_print->precision = 0;
    return (new_print);
}

void work_with_print(t_print *print)
{
    char a;
    
    a = print->type;
}

int check_letter(char format, t_print *print)
{
    if (format == 'd' || format == 'f' || format == 'c' || format == 's'
    || format == 'o' || format == 'x' || format == 'X' || format == 'F' || format == 'p')
    {
        print->type = format;
        return (0);
    }
    if (format == '+' || format == '-' || format == '%' || format == ' ' 
    || format == '#' || format == '0')
    {
        if (format == '%')
        {
            ft_putchar('%');
            return (0);
        }
        print->flag = format;
        return (1);
    }
    return (0);
}


int parser(va_list list, char *format)
{
    int i;
    t_print  *print;

    i = 0;
    print = NULL;
    print = print_init(print);
    while (format[i] != '\0')
    {
        if (format[i] == '%')
        {
            i++;
            while(check_letter((format[i]), print) && format[i])
                i++;
            work_with_print(print);
            clear_init(print);
        }
        else
        {
            ft_putchar(format[i]);
            i++;
        }
    }
    va_end(list);
    return (1);
}

int ft_printf(const char *format, ...)
{
    va_list list;
    int     ret;

    va_start(list, (char*)format);
    ret = parser(list, (char*)format);
    //va_end(list);
    return (0);     //возвращает 1, если все хорошо, мб по другому?
}
