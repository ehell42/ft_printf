/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   work_with.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alexzudin <alexzudin@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/06 10:57:08 by alexzudin         #+#    #+#             */
/*   Updated: 2020/04/20 08:56:56 by alexzudin        ###   ########.fr       */
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
    look_at_width(check_nbr_length(nbr, 16), ft_atoi((char*)(print->width)), 0);
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

void                work_with_unsigned_int(t_print *print, va_list list)    //works + width
{
    unsigned int n;

    n = va_arg(list, unsigned int);
    look_at_width(check_nbr_length(n, 10), ft_atoi((char*)(print->width)), 0);
	if (n >= 10)
	{
		ft_putnbr(n / 10);
		ft_putchar(n % 10 + '0');
	}
	else
		ft_putchar(n + '0');
}

unsigned int        check_nbr_length(unsigned int nbr, int base)
{
    unsigned int len;

    len = 0;
    if (nbr == 0)
        return (1);
    while (nbr > 0)
    {
        nbr /= base;
        len++;
    }
    return (len);
}

void                look_at_width(unsigned int nbr, unsigned int width, int sign)
{
    int i;

    if (sign)
        width--;
    if (width > nbr)
    {
        i = width - nbr;
        while (i > 0)
        {
            ft_putchar(' ');
            i--;
        }
    }
}
