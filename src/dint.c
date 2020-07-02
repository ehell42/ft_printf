/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dint.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alexzudin <alexzudin@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/21 12:40:11 by alexzudin         #+#    #+#             */
/*   Updated: 2020/07/02 10:30:15 by alexzudin        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	work_with_int(t_print *print, va_list list, int *count)
{
    long long int	nbr;
    unsigned int    width;
    unsigned int    len;
    unsigned int    pres;

    if (*((char*)(print->width)) == '*')
        width = va_arg(list, int);
    else
        width = ft_atoi((char*)(print->width));
    if (*((char*)(print->precision)) == '*')
        pres = va_arg(list, int);
    else
        pres = ft_atoi((char*)(print->precision));
    nbr = dbuffer(print, list);
    if (isit(&nbr, print) == 1)
        print->minus = 1;
    len = checklength(&nbr, 10, print);
    checkprd(&len, pres, print, nbr);
    look_at_width(len, width, print, &nbr);
    if (width > len)
        *count = *count + width;
    else
        *count = *count + len;
    if (((print->flag->probel == 1 && print->minus == 0 && print->flag->plus == 0)) && print->haveprecision == 0)
        *count = *count + 1;
}

long long int dbuffer(t_print *p, va_list list)
{
	long long int lld;
	signed char a;
	if (p->razmer[0] == ' ' && p->razmer[1] == ' ')
	{
		lld = (int)va_arg(list, int);
		return ((int)lld);
	}
    if (p->razmer[0] == 'l' && p->razmer[1] == ' ')
	{
		lld = (long int)va_arg(list, long int);
		return ((long int)lld);
	}
    if (p->razmer[0] == 'l' && p->razmer[1] == 'l')
	{
		lld = (long long int)va_arg(list, long long int);
		return ((long long int)lld);
	}
    if (p->razmer[0] == 'h' && p->razmer[1] == ' ')
	{
		lld = (short int)va_arg(list, int);
		return ((short int)lld);
	}
    if (p->razmer[0] == 'h' && p->razmer[1] == 'h')
	{
		a = (signed char)va_arg(list, int);
        lld = (int)a;
		return ((int)lld);
	}
	return (0);
}

unsigned int checklength(void *nbr, int base, t_print *p)
{
	int nbr1;
	short int nbr2;
	int nbr3;
    long int nbr4;
    long long nbr5;

	if (p->razmer[0] == ' ' && p->razmer[1] == ' ')
	{
		nbr1 = *((int*)nbr);
		return (check_nbr_length(nbr1, base, p));
	}
	else if (p->razmer[0] == 'h' && p->razmer[1] == ' ')
	{
		nbr2 = *((short int*)nbr);
		return (check_nbr_lengthshort(nbr2, (short int)base, p));
	}
	else if (p->razmer[0] == 'h' && p->razmer[1] == 'h')
	{
		nbr3 = *((signed char*)nbr);
		return (check_nbr_lengthshort(nbr3, base, p));
	}
    else if (p->razmer[0] == 'l' && p->razmer[1] == ' ')
	{
		nbr4 = *((long int*)nbr);
		return (check_nbr_length(nbr4, base, p));
	}
    else if (p->razmer[0] == 'l' && p->razmer[1] == 'l')
	{
		nbr5 = *((long long int*)nbr);
		return (check_nbr_length(nbr5, base, p));
	}
	return (0);
}

unsigned int        check_nbr_length(long long int nbr, int base, t_print *p)
{
    unsigned int len;
    unsigned long long int n;

    len = 0;
    if (nbr >= 0 && p->flag->plus == 1)
        len++;
    if (nbr == 0)
        return (len + 1);
    if (nbr < 0)
    {
        n = nbr * -1;
        len++;
    }
    else
        n = nbr;
    while (n > 0)
    {
        n /= base;
        len++;
    }
    return (len);
}

unsigned int        check_nbr_lengthshort(short int nbr, short int base, t_print *p)
{
    unsigned int len;

    len = 0;
    if (nbr == -32768)
        return (6);
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

int isit(void *nbr, t_print *p)
{
    if (p->razmer[0] == ' ' && p->razmer[1] == ' ')
	{
		if ((*(int*)nbr) < 0)
		    return (1);
	}
    if (p->razmer[0] == 'l' && p->razmer[1] == ' ')
	{
		if ((*(long int*)nbr) < 0)
		    return (1);
	}
	else if (p->razmer[0] == 'h' && p->razmer[1] == ' ')
	{
		if ((*(short int*)nbr) < 0)
		    return (1);
	}
	else if (p->razmer[0] == 'h' && p->razmer[1] == 'h')
	{
		if ((*(int*)nbr) < 0)
		    return (1);
	}
    return (0);
}

void itis(void *nbr, t_print *p)
{
    if (p->razmer[0] == ' ' && p->razmer[1] == ' ')
	{
		(*((int*)nbr)) = (*((int*)nbr)) * -1;
	}
    if (p->razmer[0] == 'l' && p->razmer[1] == ' ')
	{
		(*((long int*)nbr)) = (*((long int*)nbr)) * -1;
	}
	else if (p->razmer[0] == 'h' && p->razmer[1] == ' ')
	{
		(*((short int*)nbr)) = (*((short int*)nbr)) * -1;
	}
	else if (p->razmer[0] == 'h' && p->razmer[1] == 'h')
	{
		(*((int*)nbr)) = (*((int*)nbr)) * -1;
	}
}