/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   work_with.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alexzudin <alexzudin@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/06 10:57:08 by alexzudin         #+#    #+#             */
/*   Updated: 2020/06/30 14:21:39 by alexzudin        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"


void                work_with_unsigned_int(t_print *print, va_list list, int *count) //works all without hh h l ll
{
    void            *n;
    unsigned int    width;
    unsigned int    len;
    unsigned int    pres;

    len = 0;
    if (*((char*)(print->width)) == '*')
        width = va_arg(list, int);
    else
        width = ft_atoi((char*)(print->width));
    if (*((char*)(print->precision)) == '*')
        pres = va_arg(list, int);
    else
        pres = ft_atoi((char*)(print->precision));
    n = gethecta(print, list);
    len = countcocta(n, print, 10, pres);
    checkprd(&len, pres, print, *(unsigned int*)n);
    look_at_width(len, width, print, n);
    if (width > len)
        *count = *count + width;
    else
        *count = *count + len;
}

void                look_at_width(unsigned int len, unsigned int width, t_print *p, void *data)
{
    char symbol;

    symbol = ' ';
    if (p->flag->plus == 0 && p->flag->probel == 1 && (p->type == 'f' || p->type == 'F' || p->type == 'd' || p->type == 'i') && p->minus == 0)
        putlesswdth(' ', &width);
    if(p->flag->minus == 1)
        outputdata(data, p);
    else if (p->flag->zero == 1)
    {
        if ((*((char*)(p->precision)) == '0' || p->minus == 1) && p->haveprecision != 1)
            symbol = '0';
        if (p->minus == 1 && p->haveprecision != 1)
        {
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

void        printing(unsigned int width, unsigned int len,char symbol, t_print *p)
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