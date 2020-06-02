/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   func2.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alexzudin <alexzudin@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/01 15:33:16 by alexzudin         #+#    #+#             */
/*   Updated: 2020/06/02 16:32:29 by alexzudin        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void checkforflag(char **format, t_print *print)
{
	if (**format == '+')
		print->flag->plus = 1;
	if (**format == '-')
		print->flag->minus = 1;
	if (**format == '#')
		print->flag->ortokop = 1;
	if (**format == ' ')
		print->flag->probel = 1;
	if (**format == '0')
		print->flag->zero = 1;
}

void outputdata(void *data, t_print *p)
{
	if ((p->flag->plus == 1 && p->flag->zero == 0 && p->minus == 0) || (p->flag->plus == 1 && p->flag->zero == 1 && p->minus == 0 && p->flag->minus == 1))
		ft_putchar('+');
	if (p->minus == 1 && p->flag->zero == 0 && p->haveprecision == 1)
	{
		ft_putchar('-');
		(*(int*)data) = (*(int*)data) * -1;
	}
	if (p->lenforpr != 0)
	{
		while (p->lenforpr > 0)
		{
			ft_putchar('0');
			(p->lenforpr)--;
		}
	}
	if (p->type == 'd' && p->helper != 1)
		ft_putnbr(*((int*)data));
	if (p->type == 'c')
		ft_putchar(*((char*)data));
	if (p->type == 's' && p->helper != 1 && ((char*)data) != NULL)
		ft_putstr(((char*)data));
	else if (p->type == 's' && p->helper != 1)
		ft_putstr("(null)");
}

void putlesswdth(char a, unsigned int *width)
{
	ft_putchar(a);
	*width = (*width) - 1;
}

void	checkprd(unsigned int *len, unsigned int precision, t_print *p, int nbr)
{
	int count;

	if (p->haveprecision == 1)
	{
		if (precision >= *len)
		{
			if (p->minus == 1)
				count = *len -1;
			else
				count = *len;
			if (p->flag->plus == 1 && p->minus == 0)
				count--;
			p->lenforpr = precision - count;
			*len = *len + p->lenforpr;
		}
		else
		{
			if (precision == 0 && nbr == 0)
			{
				p->helper = 1;
				(*len)--;
			}
		}
	}
	
}