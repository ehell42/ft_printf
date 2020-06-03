/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   work_with.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alexzudin <alexzudin@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/06 10:57:08 by alexzudin         #+#    #+#             */
/*   Updated: 2020/06/03 15:30:09 by alexzudin        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void                work_with_Hectaedral(t_print *print, va_list list)   //works + width
{
    unsigned int nbr;
    unsigned int nbr_tmp;
    char    *nbr_hex;
    t_flag    *a;
    int     len;

    a = print->flag;
    nbr = va_arg(list, unsigned int);
    print->width = 0;
    //look_at_width(check_nbr_length(nbr, 16), ft_atoi((char*)(print->width)), 0);
    if (nbr == 0)
        ft_putnbr(0);
    else
    {
        nbr_tmp = nbr;
        len = 0;
        while (nbr_tmp)
        {
            nbr_tmp /= 16;
            len++;
        }
        nbr_hex = (char*) ft_memalloc(sizeof(char) * len);
        while (len >= 0)
        {
            if (nbr % 16 < 10)
                nbr_hex[len] = '0' + nbr % 16;
            else
                nbr_hex[len] = 'A' + nbr % 16 - 10;
            nbr /= 16;
            len--;
        }
        ft_putstr(&nbr_hex[1]);
        free(nbr_hex);
    }
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
        if (*((char*)(p->precision)) == '0' || p->minus == 1)
            symbol = '0';
        if (p->minus == 1)
        {
            (*((int*)data)) = (*((int*)data)) * -1;
            ft_putchar('-');
        }
        else if (p->flag->plus == 1)
            ft_putchar('+');
    }
    printing(width, len, symbol);
    if (p->flag->minus == 0)
        outputdata(data, p);
}

void        printing(unsigned int width, unsigned int len,char symbol)
{
    int i;
    
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