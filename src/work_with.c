/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   work_with.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alexzudin <alexzudin@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/06 10:57:08 by alexzudin         #+#    #+#             */
/*   Updated: 2020/06/18 19:36:55 by alexzudin        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void                work_with_Hectaedral(t_print *print, va_list list, int *count)   //works + width
{
    unsigned int nbr;
    unsigned int    len;
    unsigned int    width;
    unsigned int    pres;

    if (*((char*)(print->width)) == '*')
        width = va_arg(list, int);
    else
        width = ft_atoi((char*)(print->width));
    if (*((char*)(print->precision)) == '*')
        pres = va_arg(list, int);
    else
        pres = ft_atoi((char*)(print->precision));
    nbr = va_arg(list, unsigned int);
    len = countforocta(nbr, print, 16, pres);
    if (nbr == 0 && pres == 0 && print->haveprecision == 1)
        len--;
    checkprd(&len, pres, print, nbr);
    look_at_width(len, width, print, &nbr);
    if (width > (unsigned int)len)
        *count = *count + width;
    else
        *count = *count + len;
    if (((print->flag->probel == 1 && print->minus == 0 && print->flag->plus == 0)) && print->haveprecision == 0)
        *count = *count + 1;
}

void                work_with_unsigned_int(t_print *print, va_list list, int *count) //works all without hh h l ll
{
    unsigned int    n;
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
    n = va_arg(list, unsigned int);
    len = lenunsigned(n);
    checkprd(&len, pres, print, n);
    look_at_width(len, width, print, &n);
    if (width > len)
        *count = *count + width;
    else
        *count = *count + len;
}

unsigned int        check_nbr_length(long long int nbr, int base, t_print *p)
{
    unsigned int len;

    len = 0;
    if (nbr >= 0 && p->flag->plus == 1)
        len++;
    if (nbr == 0)
        return (len + 1);
    if (nbr < 0)
    {
        nbr = nbr * -1;
        len++;
    }
    while (nbr > 0)
    {
        nbr /= base;
        len++;
    }
    return (len);
}

void                look_at_width(unsigned int len, unsigned int width, t_print *p, void *data)
{
    char symbol;

    symbol = ' ';
    if (p->flag->plus == 0 && p->flag->probel == 1 && (p->type == 'f' || p->type == 'F' || p->type == 'd') && (*((int*)data) > 0))
        putlesswdth(' ', &width);
    if(p->flag->minus == 1)
        outputdata(data, p);
    else if (p->flag->zero == 1)
    {
        if ((*((char*)(p->precision)) == '0' || p->minus == 1) && p->haveprecision != 1)
            symbol = '0';
        if (p->minus == 1 && p->haveprecision != 1)
        {
            (*((int*)data)) = (*((int*)data)) * -1;
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