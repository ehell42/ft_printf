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

void	work_with_unsigned_int(t_print *print, va_list list, int *count)
{
	int				len;
	long long int	n;

	len = 0;
	if (print->width < 0)
	{
		print->width *= -1;
		print->f->m = 1;
	}
	n = gethecta(print, list);
	len = countcocta(&n, print, 10, print->precision);
	checkprd(&len, print->precision, print, n);
	look_at_w(len, print, &n);
	if (print->width > len)
		*count = *count + print->width;
	else
		*count = *count + len;
}

void	look_at_w(unsigned int len, t_print *p, void *d)
{
	char symbol;

	symbol = ' ';
	if (p->f->p == 0 && p->f->pr == 1 && (p->t == 'f'
	|| p->t == 'F' || p->t == 'd' || p->t == 'i') && p->m == 0)
		putlesswdth(' ', p);
	if (p->f->m == 1)
		outputdata(d, p);
	else if (p->f->z == 1)
	{
		if (((p->precision == 0 || p->m == 1) && p->hp != 1)
		|| (p->hp == 1 && p->precision < 0) || p->t == 'f')
			symbol = '0';
		if ((p->m == 1 && p->hp != 1) || l(p))
		{
			if (p->t != 'f')
				itis(d, p);
			ft_putchar('-');
		}
		else if (p->f->p == 1 && p->m == 0 && ((p->width < p->precision) || p->hp == 0))
			ft_putchar('+');
	}
	printing(len, symbol, p, d);
	if (p->f->m == 0)
		outputdata(d, p);
}

void	printing(unsigned int len, char symbol, t_print *p, void *d)
{
	int i;
	if (p->f->o == 1 && symbol == '0' && p->t == 'x' && *(long long int*)d != 0 && p->width != 0)
		ft_putstr("0x");
	if (p->f->o == 1 && symbol == '0' && p->t == 'X' && *(long long int*)d != 0 && p->width != 0)
		ft_putstr("0X");
	if ((unsigned int)p->width > len)
	{
		i = (unsigned int)p->width - len;
		while (i > 0)
		{
			ft_putchar(symbol);
			i--;
		}
	}
}

int		l(t_print *p)
{
	if (p->t == 'f' && p->m == 1)
		return (1);
	else
		return (0);
}
