/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   work_with.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alexzudin <alexzudin@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/06 10:57:08 by alexzudin         #+#    #+#             */
/*   Updated: 2020/07/10 14:50:02 by alexzudin        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void    work_with_unsigned_int(t_print *print, va_list list, int *count)
{
    long long int   n;
    int             len;

    len = 0;
    if (print->width < 0)
	{
		print->width *= -1;
		print->flag->minus = 1;
	}
    n = gethecta(print, list);
    len = countcocta(&n, print, 10, print->precision);
    checkprd(&len, print->precision, print, n);
    look_at_w(len, print->width, print, &n);
    if (print->width> len)
        *count = *count + print->width;
    else
        *count = *count + len;
}

void    look_at_w(unsigned int len, unsigned int width, t_print *p, void *data)
{
    char symbol;

    symbol = ' ';
    if (p->flag->plus == 0 && p->flag->probel == 1 && (p->type == 'f' || p->type == 'F' || p->type == 'd' || p->type == 'i') && p->minus == 0)
        {putlesswdth(' ', &width);}
    if(p->flag->minus == 1)
        outputdata(data, p);
    else if (p->flag->zero == 1)
    {
        if (((p->precision == 0 || p->minus == 1 ) && p->haveprecision != 1) || (p->haveprecision == 1 && p->precision < 0) || p->type == 'f')
            symbol = '0';
        if ((p->minus == 1 && p->haveprecision != 1) || (p->type == 'f' && p->minus == 1))
        {
            if (p->type != 'f')
                itis(data, p);
            ft_putchar('-');
        }
        else if (p->flag->plus == 1)
            ft_putchar('+');
    }
    printing(width, len, symbol, p);
    if (p->flag->minus == 0)
        outputdata(data, p);
}

void    printing(unsigned int width, unsigned int len,char symbol, t_print *p)
{
    int i;
    
    if (p->flag->ortokop == 1 && symbol == '0' && (p->type == 'x' || p->type == 'X'))
		ft_putstr("0x");
    if (width > len)
    {
        i = width - len;
        while (i > 0)
        {
            ft_putchar(symbol);
            i--;
        }
    }
}
