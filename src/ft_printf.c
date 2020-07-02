/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alexzudin <alexzudin@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/11 18:36:38 by aguiller          #+#    #+#             */
/*   Updated: 2020/07/01 12:30:13 by alexzudin        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

t_print    *clear_init(t_print *new_print)
{
    t_flag *flagclean;
    flagclean = new_print->flag;
    flagclean->plus = 0;
	flagclean->minus = 0;
	flagclean->probel = 0;
	flagclean->zero = 0;
    flagclean->percent = 0;
    new_print->type = 0;
    new_print->minus = 0;
    new_print->helper = 0;
    new_print->havewidth = 0;
    new_print->lenforpr = 0;
    new_print->haveprecision = 0;
    new_print->width = "0";
    new_print->precision = "0";
    new_print->razmer[0] = ' ';
    new_print->razmer[1] = ' ';
    return (new_print);
}

void work_with_print(t_print *print, va_list list, int *count)
{
    char a;
    
    if (print)
    {
        a = print->type;
        if (print->flag->percent == 1)
            work_with_percent(print, list, count);
        else if (a == 'd' || a == 'i')
            work_with_int(print, list, count);
     //   else if (a == 'f' || a == 'F')
     //       work_with_float(print, list);
        else if (a == 'u' || a == 'U')
            work_with_unsigned_int(print, list, count);
        else if (a == 'c')
            work_with_char(print, list, count);
        else if (a == 's')
            work_with_string(print, list, count);
        else if (a == 'o')
            work_with_octaedral(print, list, count);
        else if (a == 'x')
            work_with_hectaedral(print, list, count);
        else if (a == 'X')
            work_with_hectaedral(print, list, count);
     //   else if (a == 'p')
     //       work_with_pointer(print, list);
    }
}

int check_letter(char **format, t_print *print)
{
    if (**format == 'd' || **format == 'f' || **format == 'c' || **format == 's' || **format == 'o' || **format == 'x' || **format == 'X' || **format == 'F' || **format == 'p' || **format == 'u' || **format == 'U' || **format == 'i')
        return(checkforextra('t', format, print));
    if (**format == '+' || **format == '-' || **format == '%' || **format == ' ' 
    || **format == '#' || **format == '0')
        return (checkforextra('f',format, print));
    if ((**format >= '0' && **format <= '9') || **format == '*')
        return (checkforextra('w', format, print));
    if (**format == '.' && **(format + 1))
        return (checkforextra('p', format, print));
    if (**format == 'h' || **format == 'l' || **format == 'j' || **format == 'z')
        return (checkforextra('s', format, print));
    return (exits(print));
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
            work_with_print(print, list, &count);
            clear_init(print);
        }
        else
        {
            ft_putchar(*format);
            count++;
            format++;
        }
    }
    freeinit(&print);
    return (count);
}

int ft_printf(const char *format, ...)
{
    int count;
    va_list list;
    count = 0;
    va_start(list, (char*)format);
    count = parser(list, (char*)format, count);
    va_end(list);
    return (count);
}

void freeinit(t_print  **print)
{
    t_flag *flagclean;

    flagclean = (*print)->flag;
    (*print)->flag = NULL;
    free(flagclean);
    //free(*print);
}