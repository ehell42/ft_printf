/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dint.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alexzudin <alexzudin@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/21 12:40:11 by alexzudin         #+#    #+#             */
/*   Updated: 2020/07/10 15:39:54 by alexzudin        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	work_with_int(t_print *p, va_list list, int *count)
{
    long long int	nbr;
    int    len;
	char	*a;

    nbr = dbuffer(p, list);
    if (nbr < 0)
        p->minus = 1;
	if (p->width < 0)
	{
		p->width *= -1;
		p->flag->minus = 1;
	}
    len = checklength(&nbr, 10, p);
    checkprd(&len, p->precision, p, nbr);
	if (p->minus == 1 && ((p->flag->zero == 1 && p->flag->minus == 0) || p->haveprecision == 1))
		nbr = itis(&nbr, p);
	a = itoa(nbr);
    look_at_w(len, p->width, p, a);
	free(a);
    if (p->width > len)
        *count = *count + p->width;
    else
        *count = *count + len;
    if (((p->flag->probel == 1 && p->minus == 0 && p->flag->plus == 0)) && p->haveprecision == 0 && p->havewidth == 0)
        *count = *count + 1;
}

long long int dbuffer(t_print *p, va_list list)
{
	long long int lld;
	signed char a;
	if ((p->razmer[0] == ' ' && p->razmer[1] == ' ') || (p->razmer[0] == 'l' && p->razmer[1] == 'h'))
	{
		lld = (int)va_arg(list, int);
		return ((int)lld);
	}
    else if (p->razmer[0] == 'l' && p->razmer[1] == ' ')
	{
		lld = (long int)va_arg(list, long int);
		return ((long int)lld);
	}
    else if ((p->razmer[0] == 'l' && p->razmer[1] == 'l') || ((p->razmer[0] == 'j' || p->razmer[0] == 'z') && p->razmer[1] == 'h'))
	{
		lld = (long long int)va_arg(list, long long int);
		return ((long long int)lld);
	}
    else if (p->razmer[0] == 'h' && p->razmer[1] == ' ')
	{
		lld = (short int)va_arg(list, int);
		return ((short int)lld);
	}
    else if (p->razmer[0] == 'h' && p->razmer[1] == 'h')
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

	if ((p->razmer[0] == ' ' && p->razmer[1] == ' ') || (p->razmer[0] == 'l' && p->razmer[1] == 'h'))
	{
		nbr1 = *((int*)nbr);
		return (check_nbr_length(nbr1, base, p));
	}
	else if (p->razmer[0] == 'h' && p->razmer[1] == ' ')
	{
		nbr2 = *((short int*)nbr);
		return (check_nbr_length(nbr2, (short int)base, p));
	}
	else if (p->razmer[0] == 'h' && p->razmer[1] == 'h')
	{
		nbr3 = *((signed char*)nbr);
		return (check_nbr_length(nbr3, base, p));
	}
    else if (p->razmer[0] == 'l' && p->razmer[1] == ' ')
	{
		nbr4 = *((long int*)nbr);
		return (check_nbr_length(nbr4, base, p));
	}
    else if ((p->razmer[0] == 'l' && p->razmer[1] == 'l') || ((p->razmer[0] == 'j' || p->razmer[0] == 'z') && p->razmer[1] == 'h'))
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

long long int itis(void *nbr, t_print *p)
{
    if (p->razmer[0] == ' ' && p->razmer[1] == ' ')
		return (*((int*)nbr) = (*((int*)nbr)) * -1);
    else if (p->razmer[0] == 'l' && p->razmer[1] == ' ')
		return (*((long int*)nbr) = (*((long int*)nbr)) * -1);
	else if (p->razmer[0] == 'h' && p->razmer[1] == ' ')
		return (*((short int*)nbr) = (*((short int*)nbr)) * -1);
	else if (p->razmer[0] == 'h' && p->razmer[1] == 'h')
		return (*((int*)nbr) = (*((int*)nbr)) * -1);
	return (0);
}